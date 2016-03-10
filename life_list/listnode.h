
/*  File: listnode.h
 *  Date: 26 Sep 05
 *  Rev:
 *
 *  Listnode class declaration
 */

#ifndef LISTNODE_H
#define LISTNODE_H

#include <stdlib.h>
#include "entry.h"

/*******************************************************************/
/*                                                                 */
/*  List Declaration using linked-list implementation              */
/*                                                                 */
/*******************************************************************/

class ListNode
{
public:
	// constructor
	ListNode(Entry x);

	// accessors:
	inline Entry getdata() const;
	inline ListNode *getnext() const;

	// mutators
	inline void setdata(Entry x);
	inline void setnext(ListNode *n);


private:
	Entry entry;
	ListNode *next;
};

#include "listnode_inl.h"

#endif
