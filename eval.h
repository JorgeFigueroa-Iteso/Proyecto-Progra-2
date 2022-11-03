#ifndef EVAL_H_
#define EVAL_H_

#include <stddef.h>

typedef enum {false, true} bool;

/*		Dato Genético		*/

typedef void * Type;

/*		Dato Genético		*/

typedef struct strQueue *Queue;
typedef struct strStack *Stack;

typedef char * opdr;

/*		<------  STACK  ------>		*/

void stackPush(char);
int stackPop();
int stackPeek();
bool stackisEmpty();


/*		<------  QUEUE  ------>		*/

void queue_insert(int);
void queue_delete();
void queue_check();
void queue_first_element();
void queue_size();

/* <--- checks --->*/

bool parentesis(opdr);
bool operador();

#endif