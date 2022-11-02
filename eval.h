#include <stddef.h>

#ifndef EVAL_H_
#define EVAL_H_

typedef enum{false, true} bool;

/*		Dato Genético		*/

typedef void * Type;

/*		Dato Genético		*/

typedef struct strQueue *Queue;
typedef struct strStack *Stack;

/*		Interfaz		*/

void stackPush();
int stackPop();
int stackPeek();
bool stackisEmpty();


#endif /*EVAL_H_*/