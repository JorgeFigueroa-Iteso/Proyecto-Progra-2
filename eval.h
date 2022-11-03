#include <stddef.h>

#ifndef EVAL_H_
#define EVAL_H_

typedef enum{false, true} bool;

/*		Dato Genético		*/

typedef void * Data;

/*		Dato Genético		*/

typedef struct strQueue *Queue;
typedef struct strStack *Stack;

/*		<------  STACK  ------>		*/

void stackPush(float);
void stackPop();

float stackPoped();

float stackPeek();
bool stackisEmpty();


/*		<------  QUEUE  ------>		*/

void queue_insert(char);
void queue_delete();
float queue_poped();
bool queue_check();
void queue_first_element();
char queue_size();

#endif