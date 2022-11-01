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
};

int queueSize(Queue q){
	if (q!=NULL){
		return q->size;
	}
	else{
		return 0;
	}
}

Node newNode(Data data, size_t bytes){
	Node new=malloc(sizeof(Node));
	new->data=malloc(size(bytes));
	memcpy(new->data, data, bytes);
	new->next=NULL;

	return new;
}

void enqueue(Queue q, Data data){
	if (q!=NULL){
		Node new=newNode(data, q->size_data);
		if (!queueEmpty(q)){
			q->first=new;
			q->last=new;
			q->size++;		
		}
		else{
			q->last->next=new;
			q->last=new;
			q->size++;
		}
	}	
}

//evalua si el queue tiene contenido y en la posicion en la que este esta (first o last)
bool queueEmpty(Queue q){
	if (q!=NULL){
		if (q->size==0 && q->first==NULL){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return true;
	}
}

Data peek(Queue q){
	if (q!=NULL){
		if (!queueEmpty(q)){
			return q->firs->data;
		}
		else{
			return NULL;
		}
	}
	else{
		return NULL;
	}
}

/*
Data deQueue(Queue q){
	if (q!=NULL){
		if (!queueEmpty){
			***TO DO***
		}
	}
}


*/

void queueDestroy(Queue q){
	if (q!=NULL){
		Data temp;
		while(!queueEmpty(q)){
			temp=deQueue(q);
			free(temp);
		}
		free(q);
	}
}


