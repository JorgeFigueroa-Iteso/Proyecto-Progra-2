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

//retorna el tamaño del queue
int queueSize(Queue);

//bool queueEmpty(Queue);
void queueDestry(Queue);

//agrega un elemento al final del queue
void enqueue(Queue, Data);

//muestra y remueve el primer elemento en el queue
Data dequeue(Queue);

//muestra el primer elemento en el queue
Data peek(Queue);







#endif /*EVAL_H_*/