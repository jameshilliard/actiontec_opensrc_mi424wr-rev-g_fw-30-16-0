/* SwingPropertyChangeSupport.java --
   Copyright (C) 2002, 2004, 2005 Free Software Foundation, Inc.

This file is part of GNU Classpath.

GNU Classpath is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU Classpath is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU Classpath; see the file COPYING.  If not, write to the
Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
02110-1301 USA.

Linking this library statically or dynamically with other modules is
making a combined work based on this library.  Thus, the terms and
conditions of the GNU General Public License cover the whole
combination.

As a special exception, the copyright holders of this library give you
permission to link this library with independent modules to produce an
executable, regardless of the license terms of these independent
modules, and to copy and distribute the resulting executable under
terms of your choice, provided that you also meet, for each linked
independent module, the terms and conditions of the license of that
module.  An independent module is a module which is not derived from
or based on this library.  If you modify this library, you may extend
this exception to your version of the library, but you are not
obligated to do so.  If you do not wish to do so, delete this
exception statement from your version. */

package javax.swing.event;

import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeListenerProxy;
import java.beans.PropertyChangeSupport;
import java.util.ArrayList;
import java.util.EventListener;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * Provides a mechanism for registering {@link PropertyChangeListener}s and
 * forwarding {@link PropertyChangeEvent}s to those listeners.
 * 
 * @author Andrew Selkirk
 */
public final class SwingPropertyChangeSupport
    extends PropertyChangeSupport 
{

  private static final long serialVersionUID = 7162625831330845068L;

  /**
   * Storage for the listeners that are not linked to a specific property.
   */
  private transient EventListenerList listeners;

  /**
   * Storage for the listeners that are linked (by name) to a specific property.
   * The hash table maps <code>String</code> objects (the property names) to 
   * {@link EventListenerList} instances (which record the listener(s) for the 
   * given property).
   */
  private Hashtable propertyListeners;

  /**
   * The object that is used as the default source for the 
   * {@link PropertyChangeEvent}s generated by this class.
   */
  private Object source;

  /**
   * Creates a new instance.
   * 
   * @param source  the source (<code>null</code> not permitted).
   * 
   * @throws NullPointerException if <code>source</code> is <code>null</code>.
   */
  public SwingPropertyChangeSupport(Object source) 
  {
    super(source);
    this.source = source;
    this.listeners = new EventListenerList();
    this.propertyListeners = new Hashtable();
  }

  /**
   * Registers <code>listener</code> to receive notification of any future
   * {@link PropertyChangeEvent}s generated by this instance.
   * 
   * @param listener  the listener (<code>null</code> is ignored).
   * 
   * @see #removePropertyChangeListener(PropertyChangeListener)
   */
  public synchronized void addPropertyChangeListener(PropertyChangeListener 
          listener) 
  {
    listeners.add(PropertyChangeListener.class, listener);
  } 

  /**
   * Registers <code>listener</code> to receive notification of any future
   * {@link PropertyChangeEvent}s generated by this instance for the named
   * property.
   * 
   * @param propertyName  the property name.
   * @param listener  the listener.
   * 
   * @see #removePropertyChangeListener(String, PropertyChangeListener)
   */
  public synchronized void addPropertyChangeListener(String propertyName, 
          PropertyChangeListener listener) 
  {
    EventListenerList list;
    list = (EventListenerList) propertyListeners.get(propertyName);
    if (list == null) 
      {
        list = new EventListenerList();
        propertyListeners.put(propertyName, list);
      }
    list.add(PropertyChangeListener.class, listener);
  }

  /**
   * Removes <code>listener</code> from the list of registered listeners, so 
   * that it will no longer receive notification of property change events.
   * 
   * @param listener  the listener to remove.
   */
  public synchronized void removePropertyChangeListener(PropertyChangeListener 
          listener) 
  {
    listeners.remove(PropertyChangeListener.class, listener);
  }

  /**
   * Removes <code>listener</code> from the list of registered listeners for
   * the named property, so that it will no longer receive notification of 
   * property change events.
   * 
   * @param propertyName  the property name.
   * @param listener  the listener to remove.
   */
  public synchronized void removePropertyChangeListener(String propertyName, 
          PropertyChangeListener listener) 
  {
    EventListenerList list;
    list = (EventListenerList) propertyListeners.get(propertyName);
    if (list == null)
      return;
    list.remove(PropertyChangeListener.class, listener);
    if (list.getListenerCount() == 0) 
      {
        propertyListeners.remove(propertyName);
      } 
  } 

  /**
   * Returns an array of the {@link PropertyChangeListener}s registered with
   * this <code>SwingPropertyChangeSupport</code> instance.
   * 
   * @return The array of listeners.
   * 
   * @since 1.4
   */
  public synchronized PropertyChangeListener[] getPropertyChangeListeners() 
  {
    // fetch the named listeners first so we know how many there are
    List namedListeners = new ArrayList();
    Set namedListenerEntries = propertyListeners.entrySet();
    Iterator iterator = namedListenerEntries.iterator();
    while (iterator.hasNext())
      {
        Map.Entry e = (Map.Entry) iterator.next();
        String propertyName = (String) e.getKey();
        EventListenerList ell = (EventListenerList) e.getValue();
        if (ell != null)
          {
            Object[] list = ell.getListenerList();
            for (int i = 0; i < list.length; i += 2)
              {
                namedListeners.add(new PropertyChangeListenerProxy(propertyName, 
                    (PropertyChangeListener) list[i + 1]));
              }
          }
      }
    
    // create an array that can hold everything
    int size = listeners.getListenerCount() + namedListeners.size();
    PropertyChangeListener[] result = new PropertyChangeListener[size];
    
    // copy in the general listeners
    Object[] list = listeners.getListenerList();
    int index = 0;
    for (int i = 0; i < list.length; i += 2)
      result[index++] = (PropertyChangeListener) list[i + 1];
    
    // ...and the named listeners
    Iterator iterator2 = namedListeners.iterator();
    while (iterator2.hasNext()) 
      result[index++] = (PropertyChangeListenerProxy) iterator2.next();
    
    return result;
  }
  
  /**
   * Returns an array of all listeners that are registered to receive 
   * notification of changes to the named property.  This includes the general
   * listeners as well as those registered specifically for the named 
   * property.
   * 
   * @param propertyName  the property name.
   * 
   * @return An array of all listeners for the named property.
   */
  public synchronized PropertyChangeListener[] getPropertyChangeListeners(
          String propertyName)
  {
    EventListenerList list 
      = (EventListenerList) propertyListeners.get(propertyName);
    if (list == null)
      return getPropertyChangeListeners();
    int size = listeners.getListenerCount() + list.getListenerCount();
    PropertyChangeListener[] result = new PropertyChangeListener[size];
    
    // copy in the general listeners
    int index = 0;
    for (int i = 0; i < listeners.listenerList.length; i += 2)
      {
        result[index++] 
            = (PropertyChangeListener) listeners.listenerList[i + 1];
      }
    
    // copy in the specific listeners
    Object[] specificListeners = list.getListenerList();
    for (int i = 0; i < specificListeners.length; i += 2)
      {
        result[index++] = (PropertyChangeListener) specificListeners[i + 1];
      }
    return result;
  }

  /**
   * Creates a new {@link PropertyChangeEvent} using the given arguments (and
   * the default <code>source</code> for this 
   * <code>SwingPropertyChangeSupport</code> instance) and forwards it to all 
   * registered listeners via the 
   * {@link PropertyChangeListener#propertyChange(PropertyChangeEvent)} method.
   * <p>
   * Note that if <code>oldValue</code> and <code>newValue</code> are non-null
   * and equal, no listeners will be notified.
   * 
   * @param propertyName  the property name.
   * @param oldValue  the old value
   * @param newValue  the new value.
   */
  public void firePropertyChange(String propertyName, Object oldValue, 
          Object newValue) 
  {
    PropertyChangeEvent event;
    event = new PropertyChangeEvent(source, propertyName, oldValue, newValue);
    firePropertyChange(event);
  } 

  /**
   * Forwards <code>event</code> to registered listeners.
   * <p>
   * Note that if the event's <code>getOldValue()</code> and 
   * <code>getNewValue()</code> methods return non-null and equal values, no 
   * listeners will be notified.
   * 
   * @param event  the event.
   */
  public void firePropertyChange(PropertyChangeEvent event) 
  {
    EventListenerList list;
    EventListener[] listenerList;
    int index;
    PropertyChangeListener listener;

    // Check Values if they are equal
    if (event.getOldValue() == null && event.getNewValue() == null ||
        (event.getOldValue() != null && event.getNewValue() != null &&
              event.getOldValue().equals(event.getNewValue()))) 
      return;

    // Process Main Listener List
    listenerList = listeners.getListeners(PropertyChangeListener.class);
    for (index = 0; index < listenerList.length; index++) 
      {
        listener = (PropertyChangeListener) listenerList[index];
        listener.propertyChange(event);
      } 

    // Process Property Listener List
    list = (EventListenerList) propertyListeners.get(event.getPropertyName());
    if (list != null) 
      {
        listenerList = list.getListeners(PropertyChangeListener.class);
        for (index = 0; index < listenerList.length; index++) 
          {
            listener = (PropertyChangeListener) listenerList[index];
            listener.propertyChange(event);
          } 
      } 

  } 

  /**
   * Tell whether the specified property is being listened on or not. This
   * will only return <code>true</code> if there are listeners on all
   * properties or if there is a listener specifically on this property.
   *
   * @param propertyName the property that may be listened on
   * @return whether the property is being listened on
   * @throws NullPointerException if propertyName is null
   */
  public synchronized boolean hasListeners(String propertyName) 
  {
    if (listeners.getListenerCount() > 0)
      return true;
    else
      return (propertyListeners.get(propertyName) != null);
  } 

}
