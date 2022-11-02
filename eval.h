#ifndef EVAL_H_
#define EVAL_H_
#include <stddef.h>
#include <stdbool.h>

typedef void *Data;


//definicion de expresiones (operador y operando)
typedef char * opdr;
typedef double * opdo; 


/* <--- queue --->*/

typedef struct queue * Queue;

Queue queueCreate(size_t);

//agrega un elemento al final del queue
void enqueue(Queue, Data);

//retorna el tamaño del queue
int queueSize(Queue);

//bool queueEmpty(Queue);
void queueDestroy(Queue);


//muestra y remueve el primer elemento en el queue
Data deQueue(Queue);

//muestra el primer elemento en el queue
Data peek(Queue);

bool queueEmpty(Queue);


/* <--- stack --->*/

typedef struct stack * Stack

Stack stack_create();
int stack_size(Stack);
bool stack_isEmpty(Stack);
Data stack_top(Stack);
void stack_push(Stack, DATA);
Data stack_pop(Stack);
void stack_destroy(Stack);
void print_stack(Stack);






#endif /*EVAL_H_*/