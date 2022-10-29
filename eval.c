#include "eval.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/*	<--- Comienzo de operaciones desde el .h --->	*/

struct strNode{
	Type data;
	struct strNode *next;
}
typedef struct strNode *Node;

struct strQueue{
	int opdo;
	int opor;
	Node last;
	Node first;
	size_t size;
	unsigned int size;
}
