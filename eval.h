#include <stddef.h>

#ifndef EVAL_H_
#define EVAL_H_
// #include <stdbool.h>

typedef enum{false, true} bool;

/*		Dato Genético		*/

typedef void * Data;

/*		Dato Genético		*/

typedef struct strQueue *Queue;
typedef struct strStack *Stack;

/*		<------  STACK  ------>		*/

void stackPush();
int stackPop();
int stackPeek();
bool stack_Empty();


/*		<------  QUEUE  ------>		*/

void queue_insert();
void queue_delete();
void queue_check();
void queue_first_element();
void queue_size();

#endif