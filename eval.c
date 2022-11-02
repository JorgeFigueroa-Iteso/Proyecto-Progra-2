#include "eval.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
/*	<--- Comienzo de operaciones desde el .h --->	*/


opdr leerInput();


/* <--- queue ---> */
struct nodeQueue{
	Data data;
	struct nodeQueue *next;
}

typedef struct nodeQueue *Node;

struct strQueue{
	Node last;
	Node first;
	int size;
	size_t size;
}

Queue queueCreate(size_t bytes){
	Queue new=malloc(sizeof(struct strQueue));
	new->first=NULL;
	new->last=NULL;
	new->size_data=bytes;
	new->size=0;

	return new;
}

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


Data deQueue(Queue q){
	if (q!=NULL){
		if (!queueEmpty){
			NodePQ ret=q->first;
            DATA temp=ret->data;
            
            if(ret->next!=NULL){
                q->first=ret->next;

            }
            else
            {
                q->first=NULL;
            }
            free(ret);
            q->size--;
            return temp;
        }
        else
        {
            return NULL;
        }
    }
    else{
        return NULL;
    }
   }
	

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




/* <--- stack --->*/

struct nodeStack{
	Data data;
	struct nodeStack *last;
}

typedef struct nodeStack * nodePnr;

struct stack{
	nodePnr top;
	int size;
	size_t bytes;
}

Stack stack_create(size_t bytes){
    Stack s= malloc(sizeof(struct stack));

    s->bytes=bytes;
    s->size=0;
    s->top=NULL;
    return s;

}

int stack_size(Stack s){
    if (s!=NULL)
    {
        return s->size;
    }
    else
    {
        return -1;
    }
    
}

bool stack_isEmpty(Stack s){
    if (s != NULL)
    {
        if(s->top==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
    
}

DATA stack_top(Stack s){
    if (s!=NULL)
    {
        if(s->top!=NULL)
        {
            return s->top->data;
        }
        else 
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

NodePS newNode(DATA data){
    NodePnr new= malloc(sizeof(struct nodePnr));
    new->data=data;
    new->last=NULL;
    return new;
}

void stack_push(Stack s, DATA data){
    if(s!=NULL)
    {
        NodePnr nd=newNode(data);
        s->size++;
        nd->last=s->top;
        s->top=nd;
    }
    else
    {
        printf("Error: Stack is null");
    }
}

DATA stack_pop(Stack s){
    if(s!=NULL)
    {
        if(s->top!=NULL)
        {
            void *temp=s->top->data;

            NodePS new_top=s->top->last;
            free(s->top);
            s->top=new_top;
            s->size--;
            return temp;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

void stack_destroy(Stack s){
    if (s!=NULL)
    {
        if(s->top!=NULL && s->size!=0)
        {
            for(int i=0; i<s->size; i++)
            {
                
                if(s->top!=NULL)
                {
                    NodePnr next_node=s->top->last;
                    //destruye el top 
                    free(s->top);
                    //recorre el top
                    s->top=next_node;
                }
            }
        }
        free(s);
    }
}

