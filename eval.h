#ifndef EVAL_H_
#define EVAL_H_
#include <stddef.h>
#include <stdbool.h>

typedef void *Data;


//definicion de expresiones (operador y operando)
typedef char * opdr;
typedef double * opdo; 


//contenedores

typedef struct queue * Queue;

Queue queueCreate(size_t);

//agrega un elemento al final del queue
void enqueue(Queue, Data);

//retorna el tamaño del queue
int queueSize(Queue);

//bool queueEmpty(Queue);
void queueDestroy(Queue);


//muestra y remueve el primer elemento en el queue
//SData deQueue(Queue);

//muestra el primer elemento en el queue
Data peek(Queue);

bool queueEmpty(Queue);





#endif /*EVAL_H_*/