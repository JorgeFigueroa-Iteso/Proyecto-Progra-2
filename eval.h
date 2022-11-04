#include <stddef.h>

#ifndef EVAL_H_
#define EVAL_H_

typedef enum{false, true} bool;

/*		Dato Genético		*/

typedef void * Data;
typedef void * Type;

/*		Dato Genético		*/

typedef struct stack * Stack;
typedef struct strNode * Node;

typedef struct queue *Queue;

/*		<------  STACK  ------>		*/

Stack stack_create(size_t);
int stack_size(Stack);
bool stack_isEmpty(Stack);
Data stack_top(Stack);
void stack_push(Stack, Data);
Data stack_pop(Stack);
void stack_destroy(Stack);
void print_stack(Stack);

/*		<------  STACK  ------>		*/


/*		<------  QUEUE  ------>		*/

void queue_insert(char);
void queue_delete();
float queue_poped();
bool queue_check();
void queue_first_element();
char queue_size();

#endif