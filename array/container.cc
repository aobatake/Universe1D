
/*  File: container.c
 *  Date: 12 Sep 06
 *  Rev:  25 Sep 07
 *
 *  Container class definitions - version 2
 */

#include <stdlib.h>
#include "common.h"
#include "entry.h"
#include "container.h"

/*******************************************************************/
/*                                                                 */
/*  Simple Container Operations                                    */
/*                                                                 */
/*******************************************************************/

Container::Container()
/*  initialize a Container object
    pre:  none
    post: Container has been created and initialized to empty
 */
{
    count = 0;
}

void Container::clear()
/*  clear a Container object
    pre:  Container has been created
    post: all entries have been removed; Container is empty
 */
{
    count = 0;
}

bool Container::isempty() const
/*  tests if a Container is empty
    pre:  Container has been created
    post: returns true if Container is empty; false otherwise
 */
{
    return count == 0;
}

bool Container::isfull() const
/*  tests if a Container is full
    pre:  Container has been created
    post: returns true if Container is full; false otherwise
 */
{
    return count == MAXSIZE;
}

int Container::size() const
/*  determines the size of a Container
    pre:  Container has been created
    post: returns the number of entries in the Container
 */
{
    return count;
}

void Container::traverse(void(*Visit)(Entry))
/*  applies the operation Visit to each element of the Container
    pre: Container has been created; Visit is a function that processes
	elements of type Entry. Visit does not modify the Container.
    post: the action Visit has been applied to each element in the Container
	begining at the first
 */
{
    for(int i = 0; i < count ; i++) {
        Visit(elements[i]);
    }
}


/*******************************************************************/
/*                                                                 */
/*  More Complex Container Operations                                   */
/*                                                                 */
/*******************************************************************/

void Container::insert(Entry x, Position p)
/*  insert entry x into Container at position p (-1 is end of container)
    pre:  Container has been created, x is a valid entry, and 0 <= p <= n,
	where n is number of Container entries
    post: x is inserted in the Container at position p, all entries at p and after
	have increased in position by 1.
    error: if Container is full, nothing done and waring produced.
 */
{
    if(count == MAXSIZE) {
        printf("Container is Full");
        return;
    }

    count ++;

    p = p == -1 ? count : p;
    //count ++;
    for (int i = p + 1; i <= count ; i++) {
        elements[i] = elements[i-1];
    }

    elements[p] = x;
}

Entry Container::remove(Position p)
/*  delete and return entry at position p
    pre:  Container has been created, and 0 <= p < n, where n is number
	of Container entries
    post: entry at position p has been deleted and returned as x, all entries
	after p have decreased in position by 1
    error: if Container is shorter than p, nothing done an waring produced.
*/
{
    count --;

    int del = elements[p];

    for (int i = p; i < count; i++) {
        elements[i] = elements[i+1];
    }
    return del;
}

Entry Container::get(Position P) const
/*  return entry at position p
    pre:  Container has been created, and 0 <= p < n, where n is number
	of Container entries
    post: entry at position p has been returned as x, Container unchanged
    error: if Container is shorter than p, nothing done an waring produced.
*/
{
    if(P == -1)
        return elements[count-1];
    return elements[P];
}

void Container::replace(Entry x, Position p)
/*  replace entry at position p with x
    pre:  Container has been created, and 0 <= p < n, where n is number
	of Container entries
    post: entry at position p has been replaced with x, other entries unchanged
    error: if Container is shorter than p, nothing done an waring produced.
*/
{
    elements[p] = x;
}

