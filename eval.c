#include "eval.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/*	<--- Comienzo de operaciones desde el .h --->	*/

struct nodeQueue{
	Data data;
	struct nodeQueue *next;
};

typedef struct nodeQueue *Node;

struct strQueue{
	Node last;
	Node first;
	int size;
	size_t size;
};

Queue queueCreate(size_t bytes){
	Queue new=malloc(sizeof(struct queue));
	new->first=NULL;
	new->last=NULL;
	new->size_data=bytes;
	new->size=0;
	return new;
}
