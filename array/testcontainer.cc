
/*  File: testcontainer.c
 *  Date: 6 Sep 05
 *  Rev: 25 Sep 07
 *
 *  simple tests for container data type
 */

#include "container.h"
#include "entry.h"

void printcontainer(Entry);

int main()
{
   Container l;
   Entry a;
   int x;

	if(l.isempty()) printf("Container is empty\n");
	else printf("Container not empty\n");

	l.insert(3);
	l.insert(6);
	l.insert(9);

	if(l.isempty()) printf("Container is empty\n");
	else printf("Container not empty\n");

	x = l.size();
	printf("size of Container is %d\n", x);

	l.traverse(printcontainer);
	printf("\n");

	l.insert(5, 1);

	l.traverse(printcontainer);

	a = l.remove(2);
	printf("deleted entry %d\n", a);

	l.traverse(printcontainer);

	a = l.get(3);
	printf("retrieved entry %d\n", a);
	a = l.get(2);
	printf("retrieved entry %d\n", a);

	l.replace(6, 1);

	l.traverse(printcontainer);

	l.clear();

	x = l.size();
	printf("size of container is %d\n", x);

	if(l.isempty()) printf("Container is empty\n");
	else printf("Container not empty\n");

	l.insert(20);
	l.insert(30);
	l.traverse(printcontainer);

	l.insert(25, 1);
	l.traverse(printcontainer);

	l.insert(15, 0);
	l.traverse(printcontainer);

	a = l.remove(1);
	printf("deleted entry %d\n", a);
	l.traverse(printcontainer);

	a = l.remove(0);
	printf("deleted entry %d\n", a);
	l.traverse(printcontainer);

	a = l.remove(1);
	printf("deleted entry %d\n", a);
	l.traverse(printcontainer);

}

void printcontainer(Entry x)
{   printf("%d\n", x);   }

