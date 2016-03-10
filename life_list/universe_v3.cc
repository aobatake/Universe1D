/*  File: universe.cc
 *  Date: 27 Sep 05
 *  Rev:  v1
 *
 *  definition of universe class
 *  a simplest case with updates as a copy of the current universe
 */

#include "universe.h"
#include "entry.h"
#include "container.h"

// maximum number of generations to process
static const int MAXGEN = 3;

// symbols for cell state
const int DEAD = 0;
const int ALIVE = 1;

// Constructor and Destructors
Universe :: Universe()
{	init_to_empty();	}

Universe :: ~Universe()
{	init_to_empty();	}

// Accessors
void Universe :: display() const
{
	int live = 0;
	int live_count = count_cells(begin - 1, end);
	// show header
        printf("begin: %3d",begin - 2);
        for(int i = begin; i <= end+2; i++) printf("  ");
        printf("%3d end\n", end +2);

	// show universe
	printf("Generation %03d: ", generation);
		for(int i = begin - 1; i < end; i++){
		
			if(cells.get(i) == 1) {
				printf("%d ", cells.get(i));
				live++;
			}
			else if(cells.get(i) == 0){
				if(live == 0){
					printf("");
				}

				else if(live_count != live && live != 0 ){
					printf("%d ", cells.get(i));
				}			
			}
			

		}
			
	printf("\n");
}

// Mutators

void Universe :: clear()
{	init_to_empty();	}

void Universe :: populate()
{
	// a simple initial universe for testing
	cells.insert(DEAD);
	cells.insert(DEAD);
	cells.insert(ALIVE);
	cells.insert(ALIVE);
	cells.insert(DEAD);
	cells.insert(DEAD);
	
	end = cells.count;
}

int Universe :: update(Universe *other)
{
	other->generation = generation;
	other->begin = begin;
	other->end = end;

	// a trivial update operation which copies to the next generation.
	for(int i = begin - 1; i < end; i++){
		if(eval_cell(i) == ALIVE){
			other->cells.insert(update_live(i), i);
		}

		else {
			other->cells.insert(update_dead(i),i);
		}
	}

	other->generation++;
	
	return other->generation - MAXGEN;
}

// Private helper functions

void Universe :: init_to_empty()
{	begin = 1; 
       end = 1; 
       generation = 0;
	cells.clear();
}

void Universe :: update_from_copy(Universe &other)
{
	for(int i = begin; i <= end; i++)
	{
		other.cells.insert(cells.get(i - begin));
	}

	other.generation = generation;
	other.begin = begin;
	other.end = end;
}

Entry Universe :: update_live(Coordinate p) const{

	int live = 0;

	if(cells.get(p+1) == 1){
		live++;
	}

	if(cells.get(p+2) == 1){
		live++;
	}

	if(cells.get(p-1) == 1){
		live++;
	}

	if(cells.get(p-2) == 1){
		live++;
	}

	if(live==2){
		return ALIVE;
	}

	if(live== 1 || live == 0 || live == 3) {
		return DEAD;
	}

}

Entry Universe :: update_dead(Coordinate p) const {
	int live = 0;

	if(cells.get(p+1) == 1){
		live++;
	}

	if(cells.get(p+2) == 1){
		live++;
	}

	if(cells.get(p-1) == 1){
		live++;
	}

	if(cells.get(p-2) == 1){
		live++;
	}

	if(live==2 || live == 3){
		return ALIVE;
	}

	if(live== 1 || live == 0) {
		return DEAD;
	}

}


int Universe :: count_cells(Coordinate start, Coordinate stop) const {

	int live = 0;

	for(int i = start; i <= stop; i++){
		if(cells.get(i) == ALIVE){
			live++;
		}
	}

	return live;

}

int Universe :: eval_cell(Coordinate p) const {
	return cells.get(p);
}





