/*  File: listnode_inl.h
 *   *  Date: 26 Sep 05
 *    *  Rev:
 *     *
 *      *  Listnode class declaration
 *       */

#ifndef LISTNODE_INL_H
#define LISTNODE_INL_H

#include <stdlib.h>
#include "entry.h"


/*******************************************************************/
/*                                                                 */
/*  List Declaration using linked-list implementation              */
/*                                                                 */
/*******************************************************************/

inline ListNode::ListNode(Entry x)
                {entry = x;
}
inline Entry ListNode::getdata() const
{       return entry;
}
inline ListNode *ListNode::getnext() const
{       return next;
}
inline void ListNode::setdata(Entry x)
{       entry = x;
}
inline void ListNode::setnext(ListNode *n)
{       next = n;
}

#endif
