/* drivers/char/ser_a2232fw.h */

/* $Id: ser_a2232fw.h,v 1.2 2005/08/08 06:42:38 noams Exp $ */

/*
 * Copyright (c) 1995 Jukka Marin <jmarin@jmp.fi>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, and the entire permission notice in its entirety,
 *    including the disclaimer of warranties.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior
 *    written permission.
 *
 * ALTERNATIVELY, this product may be distributed under the terms of
 * the GNU Public License, in which case the provisions of the GPL are
 * required INSTEAD OF the above restrictions.  (This clause is
 * necessary due to a potential bad interaction between the GPL and
 * the restrictions contained in a BSD-style copyright.)
 *
 * THIS SOFTWARE IS PROVIDED `AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
                                      
/* This is the 65EC02 code by Jukka Marin that is executed by
   the A2232's 65EC02 processor (base address: 0x3800)
   Source file:	ser_a2232fw.ax
   Version:	1.3 (951029)
   Known Bugs:	Cannot send a break yet
*/
static unsigned char a2232_65EC02code[] = {
	0x38, 0x00, 0xA2, 0xFF, 0x9A, 0xD8, 0xA2, 0x00, 
	0xA9, 0x00, 0xA0, 0x54, 0x95, 0x00, 0xE8, 0x88, 
	0xD0, 0xFA, 0x64, 0x5C, 0x64, 0x5E, 0x64, 0x58, 
	0x64, 0x59, 0xA9, 0x00, 0x85, 0x55, 0xA9, 0xAA, 
	0xC9, 0x64, 0x90, 0x02, 0xE6, 0x55, 0xA5, 0x54, 
	0xF0, 0x03, 0x4C, 0x92, 0x38, 0xA9, 0x98, 0x8D, 
	0x06, 0x44, 0xA9, 0x0B, 0x8D, 0x04, 0x44, 0xAD, 
	0x02, 0x44, 0xA9, 0x80, 0x8D, 0x1A, 0x7C, 0xA9, 
	0xFF, 0x8D, 0x08, 0x7C, 0x8D, 0x0A, 0x7C, 0xA2, 
	0x00, 0x8E, 0x00, 0x44, 0xEA, 0xEA, 0xAD, 0x02, 
	0x44, 0xEA, 0xEA, 0x8E, 0x00, 0x44, 0xAD, 0x02, 
	0x44, 0x29, 0x10, 0xF0, 0xF9, 0xA9, 0x11, 0x8E, 
	0x00, 0x44, 0x8D, 0x1C, 0x7C, 0xAD, 0x02, 0x44, 
	0x29, 0x10, 0xF0, 0xF9, 0x8E, 0x1C, 0x7C, 0xAD, 
	0x08, 0x7C, 0x85, 0x57, 0xAD, 0x0A, 0x7C, 0x85, 
	0x56, 0xC9, 0xD0, 0x90, 0x05, 0xA9, 0x02, 0x4C, 
	0x82, 0x38, 0xA9, 0x01, 0x85, 0x54, 0xA9, 0x00, 
	0x8D, 0x02, 0x44, 0x8D, 0x06, 0x44, 0x8D, 0x04, 
	0x44, 0x4C, 0x92, 0x38, 0xAD, 0x00, 0x7C, 0xC5, 
	0x5C, 0xF0, 0x1F, 0xC5, 0x5E, 0xF0, 0x09, 0x85, 
	0x5E, 0xA9, 0x40, 0x85, 0x5D, 0x4C, 0xB8, 0x38, 
	0xC6, 0x5D, 0x10, 0x0E, 0xA6, 0x58, 0x9D, 0x00, 
	0x17, 0xE8, 0xE4, 0x59, 0xF0, 0x04, 0x86, 0x58, 
	0x85, 0x5C, 0x20, 0x23, 0x3A, 0xA5, 0x07, 0xF0, 
	0x0F, 0xA5, 0x0A, 0x85, 0x0B, 0xA5, 0x08, 0x09, 
	0x10, 0x8D, 0x06, 0x44, 0x64, 0x02, 0x64, 0x07, 
	0xA5, 0x00, 0xE5, 0x01, 0xC9, 0xC8, 0xA5, 0x09, 
	0x29, 0xF3, 0xB0, 0x02, 0x09, 0x08, 0x8D, 0x04, 
	0x44, 0xA5, 0x06, 0xF0, 0x08, 0xA5, 0x03, 0x85, 
	0x04, 0x64, 0x02, 0x64, 0x06, 0x20, 0x23, 0x3A, 
	0xA5, 0x13, 0xF0, 0x0F, 0xA5, 0x16, 0x85, 0x17, 
	0xA5, 0x14, 0x09, 0x10, 0x8D, 0x06, 0x4C, 0x64, 
	0x0E, 0x64, 0x13, 0xA5, 0x0C, 0xE5, 0x0D, 0xC9, 
	0xC8, 0xA5, 0x15, 0x29, 0xF3, 0xB0, 0x02, 0x09, 
	0x08, 0x8D, 0x04, 0x4C, 0xA5, 0x12, 0xF0, 0x08, 
	0xA5, 0x0F, 0x85, 0x10, 0x64, 0x0E, 0x64, 0x12, 
	0x20, 0x23, 0x3A, 0xA5, 0x1F, 0xF0, 0x0F, 0xA5, 
	0x22, 0x85, 0x23, 0xA5, 0x20, 0x09, 0x10, 0x8D, 
	0x06, 0x54, 0x64, 0x1A, 0x64, 0x1F, 0xA5, 0x18, 
	0xE5, 0x19, 0xC9, 0xC8, 0xA5, 0x21, 0x29, 0xF3, 
	0xB0, 0x02, 0x09, 0x08, 0x8D, 0x04, 0x54, 0xA5, 
	0x1E, 0xF0, 0x08, 0xA5, 0x1B, 0x85, 0x1C, 0x64, 
	0x1A, 0x64, 0x1E, 0x20, 0x23, 0x3A, 0xA5, 0x2B, 
	0xF0, 0x0F, 0xA5, 0x2E, 0x85, 0x2F, 0xA5, 0x2C, 
	0x09, 0x10, 0x8D, 0x06, 0x5C, 0x64, 0x26, 0x64, 
	0x2B, 0xA5, 0x24, 0xE5, 0x25, 0xC9, 0xC8, 0xA5, 
	0x2D, 0x29, 0xF3, 0xB0, 0x02, 0x09, 0x08, 0x8D, 
	0x04, 0x5C, 0xA5, 0x2A, 0xF0, 0x08, 0xA5, 0x27, 
	0x85, 0x28, 0x64, 0x26, 0x64, 0x2A, 0x20, 0x23, 
	0x3A, 0xA5, 0x37, 0xF0, 0x0F, 0xA5, 0x3A, 0x85, 
	0x3B, 0xA5, 0x38, 0x09, 0x10, 0x8D, 0x06, 0x64, 
	0x64, 0x32, 0x64, 0x37, 0xA5, 0x30, 0xE5, 0x31, 
	0xC9, 0xC8, 0xA5, 0x39, 0x29, 0xF3, 0xB0, 0x02, 
	0x09, 0x08, 0x8D, 0x04, 0x64, 0xA5, 0x36, 0xF0, 
	0x08, 0xA5, 0x33, 0x85, 0x34, 0x64, 0x32, 0x64, 
	0x36, 0x20, 0x23, 0x3A, 0xA5, 0x43, 0xF0, 0x0F, 
	0xA5, 0x46, 0x85, 0x47, 0xA5, 0x44, 0x09, 0x10, 
	0x8D, 0x06, 0x6C, 0x64, 0x3E, 0x64, 0x43, 0xA5, 
	0x3C, 0xE5, 0x3D, 0xC9, 0xC8, 0xA5, 0x45, 0x29, 
	0xF3, 0xB0, 0x02, 0x09, 0x08, 0x8D, 0x04, 0x6C, 
	0xA5, 0x42, 0xF0, 0x08, 0xA5, 0x3F, 0x85, 0x40, 
	0x64, 0x3E, 0x64, 0x42, 0x20, 0x23, 0x3A, 0xA5, 
	0x4F, 0xF0, 0x0F, 0xA5, 0x52, 0x85, 0x53, 0xA5, 
	0x50, 0x09, 0x10, 0x8D, 0x06, 0x74, 0x64, 0x4A, 
	0x64, 0x4F, 0xA5, 0x48, 0xE5, 0x49, 0xC9, 0xC8, 
	0xA5, 0x51, 0x29, 0xF3, 0xB0, 0x02, 0x09, 0x08, 
	0x8D, 0x04, 0x74, 0xA5, 0x4E, 0xF0, 0x08, 0xA5, 
	0x4B, 0x85, 0x4C, 0x64, 0x4A, 0x64, 0x4E, 0x20, 
	0x23, 0x3A, 0x4C, 0x92, 0x38, 0xAD, 0x02, 0x44, 
	0x89, 0x08, 0xF0, 0x3B, 0x89, 0x02, 0xF0, 0x1B, 
	0xAD, 0x00, 0x44, 0xD0, 0x32, 0xA6, 0x00, 0xA9, 
	0x01, 0x9D, 0x00, 0x10, 0xA9, 0x01, 0x9D, 0x00, 
	0x09, 0xE8, 0xE4, 0x01, 0xF0, 0x02, 0x86, 0x00, 
	0x4C, 0x65, 0x3A, 0xA6, 0x00, 0xAD, 0x00, 0x44, 
	0x9D, 0x00, 0x09, 0x9E, 0x00, 0x10, 0xE8, 0xE4, 
	0x01, 0xF0, 0x02, 0x86, 0x00, 0x29, 0x7F, 0xC9, 
	0x13, 0xD0, 0x04, 0xA5, 0x0B, 0x85, 0x02, 0xAD, 
	0x02, 0x44, 0x29, 0x10, 0xF0, 0x2C, 0xA6, 0x05, 
	0xF0, 0x0F, 0xAD, 0x02, 0x7C, 0x29, 0x01, 0xD0, 
	0x21, 0x8E, 0x00, 0x44, 0x64, 0x05, 0x4C, 0x98, 
	0x3A, 0xA6, 0x04, 0xE4, 0x03, 0xF0, 0x13, 0xA5, 
	0x02, 0xD0, 0x0F, 0xAD, 0x02, 0x7C, 0x29, 0x01, 
	0xD0, 0x08, 0xBD, 0x00, 0x02, 0x8D, 0x00, 0x44, 
	0xE6, 0x04, 0xAD, 0x02, 0x4C, 0x89, 0x08, 0xF0, 
	0x3B, 0x89, 0x02, 0xF0, 0x1B, 0xAD, 0x00, 0x4C, 
	0xD0, 0x32, 0xA6, 0x0C, 0xA9, 0x01, 0x9D, 0x00, 
	0x11, 0xA9, 0x01, 0x9D, 0x00, 0x0A, 0xE8, 0xE4, 
	0x0D, 0xF0, 0x02, 0x86, 0x0C, 0x4C, 0xDA, 0x3A, 
	0xA6, 0x0C, 0xAD, 0x00, 0x4C, 0x9D, 0x00, 0x0A, 
	0x9E, 0x00, 0x11, 0xE8, 0xE4, 0x0D, 0xF0, 0x02, 
	0x86, 0x0C, 0x29, 0x7F, 0xC9, 0x13, 0xD0, 0x04, 
	0xA5, 0x17, 0x85, 0x0E, 0xAD, 0x02, 0x4C, 0x29, 
	0x10, 0xF0, 0x2C, 0xA6, 0x11, 0xF0, 0x0F, 0xAD, 
	0x02, 0x7C, 0x29, 0x02, 0xD0, 0x21, 0x8E, 0x00, 
	0x4C, 0x64, 0x11, 0x4C, 0x0D, 0x3B, 0xA6, 0x10, 
	0xE4, 0x0F, 0xF0, 0x13, 0xA5, 0x0E, 0xD0, 0x0F, 
	0xAD, 0x02, 0x7C, 0x29, 0x02, 0xD0, 0x08, 0xBD, 
	0x00, 0x03, 0x8D, 0x00, 0x4C, 0xE6, 0x10, 0xAD, 
	0x02, 0x54, 0x89, 0x08, 0xF0, 0x3B, 0x89, 0x02, 
	0xF0, 0x1B, 0xAD, 0x00, 0x54, 0xD0, 0x32, 0xA6, 
	0x18, 0xA9, 0x01, 0x9D, 0x00, 0x12, 0xA9, 0x01, 
	0x9D, 0x00, 0x0B, 0xE8, 0xE4, 0x19, 0xF0, 0x02, 
	0x86, 0x18, 0x4C, 0x4F, 0x3B, 0xA6, 0x18, 0xAD, 
	0x00, 0x54, 0x9D, 0x00, 0x0B, 0x9E, 0x00, 0x12, 
	0xE8, 0xE4, 0x19, 0xF0, 0x02, 0x86, 0x18, 0x29, 
	0x7F, 0xC9, 0x13, 0xD0, 0x04, 0xA5, 0x23, 0x85, 
	0x1A, 0xAD, 0x02, 0x54, 0x29, 0x10, 0xF0, 0x2C, 
	0xA6, 0x1D, 0xF0, 0x0F, 0xAD, 0x02, 0x7C, 0x29, 
	0x04, 0xD0, 0x21, 0x8E, 0x00, 0x54, 0x64, 0x1D, 
	0x4C, 0x82, 0x3B, 0xA6, 0x1C, 0xE4, 0x1B, 0xF0, 
	0x13, 0xA5, 0x1A, 0xD0, 0x0F, 0xAD, 0x02, 0x7C, 
	0x29, 0x04, 0xD0, 0x08, 0xBD, 0x00, 0x04, 0x8D, 
	0x00, 0x54, 0xE6, 0x1C, 0xAD, 0x02, 0x5C, 0x89, 
	0x08, 0xF0, 0x3B, 0x89, 0x02, 0xF0, 0x1B, 0xAD, 
	0x00, 0x5C, 0xD0, 0x32, 0xA6, 0x24, 0xA9, 0x01, 
	0x9D, 0x00, 0x13, 0xA9, 0x01, 0x9D, 0x00, 0x0C, 
	0xE8, 0xE4, 0x25, 0xF0, 0x02, 0x86, 0x24, 0x4C, 
	0xC4, 0x3B, 0xA6, 0x24, 0xAD, 0x00, 0x5C, 0x9D, 
	0x00, 0x0C, 0x9E, 0x00, 0x13, 0xE8, 0xE4, 0x25, 
	0xF0, 0x02, 0x86, 0x24, 0x29, 0x7F, 0xC9, 0x13, 
	0xD0, 0x04, 0xA5, 0x2F, 0x85, 0x26, 0xAD, 0x02, 
	0x5C, 0x29, 0x10, 0xF0, 0x2C, 0xA6, 0x29, 0xF0, 
	0x0F, 0xAD, 0x02, 0x7C, 0x29, 0x08, 0xD0, 0x21, 
	0x8E, 0x00, 0x5C, 0x64, 0x29, 0x4C, 0xF7, 0x3B, 
	0xA6, 0x28, 0xE4, 0x27, 0xF0, 0x13, 0xA5, 0x26, 
	0xD0, 0x0F, 0xAD, 0x02, 0x7C, 0x29, 0x08, 0xD0, 
	0x08, 0xBD, 0x00, 0x05, 0x8D, 0x00, 0x5C, 0xE6, 
	0x28, 0xAD, 0x02, 0x64, 0x89, 0x08, 0xF0, 0x3B, 
	0x89, 0x02, 0xF0, 0x1B, 0xAD, 0x00, 0x64, 0xD0, 
	0x32, 0xA6, 0x30, 0xA9, 0x01, 0x9D, 0x00, 0x14, 
	0xA9, 0x01, 0x9D, 0x00, 0x0D, 0xE8, 0xE4, 0x31, 
	0xF0, 0x02, 0x86, 0x30, 0x4C, 0x39, 0x3C, 0xA6, 
	0x30, 0xAD, 0x00, 0x64, 0x9D, 0x00, 0x0D, 0x9E, 
	0x00, 0x14, 0xE8, 0xE4, 0x31, 0xF0, 0x02, 0x86, 
	0x30, 0x29, 0x7F, 0xC9, 0x13, 0xD0, 0x04, 0xA5, 
	0x3B, 0x85, 0x32, 0xAD, 0x02, 0x64, 0x29, 0x10, 
	0xF0, 0x2C, 0xA6, 0x35, 0xF0, 0x0F, 0xAD, 0x02, 
	0x7C, 0x29, 0x10, 0xD0, 0x21, 0x8E, 0x00, 0x64, 
	0x64, 0x35, 0x4C, 0x6C, 0x3C, 0xA6, 0x34, 0xE4, 
	0x33, 0xF0, 0x13, 0xA5, 0x32, 0xD0, 0x0F, 0xAD, 
	0x02, 0x7C, 0x29, 0x10, 0xD0, 0x08, 0xBD, 0x00, 
	0x06, 0x8D, 0x00, 0x64, 0xE6, 0x34, 0xAD, 0x02, 
	0x6C, 0x89, 0x08, 0xF0, 0x3B, 0x89, 0x02, 0xF0, 
	0x1B, 0xAD, 0x00, 0x6C, 0xD0, 0x32, 0xA6, 0x3C, 
	0xA9, 0x01, 0x9D, 0x00, 0x15, 0xA9, 0x01, 0x9D, 
	0x00, 0x0E, 0xE8, 0xE4, 0x3D, 0xF0, 0x02, 0x86, 
	0x3C, 0x4C, 0xAE, 0x3C, 0xA6, 0x3C, 0xAD, 0x00, 
	0x6C, 0x9D, 0x00, 0x0E, 0x9E, 0x00, 0x15, 0xE8, 
	0xE4, 0x3D, 0xF0, 0x02, 0x86, 0x3C, 0x29, 0x7F, 
	0xC9, 0x13, 0xD0, 0x04, 0xA5, 0x47, 0x85, 0x3E, 
	0xAD, 0x02, 0x6C, 0x29, 0x10, 0xF0, 0x2C, 0xA6, 
	0x41, 0xF0, 0x0F, 0xAD, 0x02, 0x7C, 0x29, 0x20, 
	0xD0, 0x21, 0x8E, 0x00, 0x6C, 0x64, 0x41, 0x4C, 
	0xE1, 0x3C, 0xA6, 0x40, 0xE4, 0x3F, 0xF0, 0x13, 
	0xA5, 0x3E, 0xD0, 0x0F, 0xAD, 0x02, 0x7C, 0x29, 
	0x20, 0xD0, 0x08, 0xBD, 0x00, 0x07, 0x8D, 0x00, 
	0x6C, 0xE6, 0x40, 0xAD, 0x02, 0x74, 0x89, 0x08, 
	0xF0, 0x3B, 0x89, 0x02, 0xF0, 0x1B, 0xAD, 0x00, 
	0x74, 0xD0, 0x32, 0xA6, 0x48, 0xA9, 0x01, 0x9D, 
	0x00, 0x16, 0xA9, 0x01, 0x9D, 0x00, 0x0F, 0xE8, 
	0xE4, 0x49, 0xF0, 0x02, 0x86, 0x48, 0x4C, 0x23, 
	0x3D, 0xA6, 0x48, 0xAD, 0x00, 0x74, 0x9D, 0x00, 
	0x0F, 0x9E, 0x00, 0x16, 0xE8, 0xE4, 0x49, 0xF0, 
	0x02, 0x86, 0x48, 0x29, 0x7F, 0xC9, 0x13, 0xD0, 
	0x04, 0xA5, 0x53, 0x85, 0x4A, 0xAD, 0x02, 0x74, 
	0x29, 0x10, 0xF0, 0x2C, 0xA6, 0x4D, 0xF0, 0x0F, 
	0xAD, 0x02, 0x7C, 0x29, 0x40, 0xD0, 0x21, 0x8E, 
	0x00, 0x74, 0x64, 0x4D, 0x4C, 0x56, 0x3D, 0xA6, 
	0x4C, 0xE4, 0x4B, 0xF0, 0x13, 0xA5, 0x4A, 0xD0, 
	0x0F, 0xAD, 0x02, 0x7C, 0x29, 0x40, 0xD0, 0x08, 
	0xBD, 0x00, 0x08, 0x8D, 0x00, 0x74, 0xE6, 0x4C, 
	0x60, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xD0, 0xD0, 0x00, 0x38, 
	0xCE, 0xC0, 
};
