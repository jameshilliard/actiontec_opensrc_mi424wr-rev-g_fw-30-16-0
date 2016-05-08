/*
 * linux/fs/ext2/xattr_trusted.c
 * Handler for trusted extended attributes.
 *
 * Copyright (C) 2001 by Andreas Gruenbacher, <a.gruenbacher@computer.org>
 */

#include <linux/sched.h>
#include <linux/fs.h>
#include <linux/ext2_fs.h>
#include <linux/ext2_xattr.h>

#define XATTR_TRUSTED_PREFIX "trusted."

static size_t
ext2_xattr_trusted_list(char *list, struct inode *inode,
			const char *name, int name_len)
{
	const int prefix_len = sizeof(XATTR_TRUSTED_PREFIX)-1;

	if (!capable(CAP_SYS_ADMIN))
		return 0;

	if (list) {
		memcpy(list, XATTR_TRUSTED_PREFIX, prefix_len);
		memcpy(list+prefix_len, name, name_len);
		list[prefix_len + name_len] = '\0';
	}
	return prefix_len + name_len + 1;
}

static int
ext2_xattr_trusted_get(struct inode *inode, const char *name,
		       void *buffer, size_t size)
{
	if (strcmp(name, "") == 0)
		return -EINVAL;
	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;
	return ext2_xattr_get(inode, EXT2_XATTR_INDEX_TRUSTED, name,
			      buffer, size);
}

static int
ext2_xattr_trusted_set(struct inode *inode, const char *name,
		       const void *value, size_t size, int flags)
{

	if (strcmp(name, "") == 0)
		return -EINVAL;
	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;
	return ext2_xattr_set(inode, EXT2_XATTR_INDEX_TRUSTED, name,
			      value, size, flags);
}

struct ext2_xattr_handler ext2_xattr_trusted_handler = {
	prefix:	XATTR_TRUSTED_PREFIX,
	list:	ext2_xattr_trusted_list,
	get:	ext2_xattr_trusted_get,
	set:	ext2_xattr_trusted_set,
};

int __init
init_ext2_xattr_trusted(void)
{
	return ext2_xattr_register(EXT2_XATTR_INDEX_TRUSTED,
				   &ext2_xattr_trusted_handler);
}

void
exit_ext2_xattr_trusted(void)
{
	ext2_xattr_unregister(EXT2_XATTR_INDEX_TRUSTED,
			      &ext2_xattr_trusted_handler);
}
