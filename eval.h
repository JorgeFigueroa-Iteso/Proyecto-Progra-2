#ifndef EVAL_H_
#define EVAL_H_

#include <stddef.h>
#include <stdbool.h>


/*		Dato Genético		*/

typedef void * Type;

/*		Dato Genético		*/

typedef struct strQueue *Queue;
//typedef char * opdr;

/*		<------  STACK  ------>		*/

typedef void * DATA;

// ========================== STACK
    //Pointer to the stack container
typedef struct stack * Stack;

Stack stack_create(size_t);
int stack_size(Stack);
bool stack_isEmpty(Stack);
DATA stack_top(Stack);
void stack_push(Stack, DATA);
DATA stack_pop(Stack);
void stack_destroy(Stack);
void print_stack(Stack);

/*		<------  QUEUE  ------>		*/

void queue_insert(int);
void queue_delete();
int queue_pop();
void queue_check();
void queue_first_element();
void queue_size();

/* <--- checks --->*/

//bool parentesis(opdr);
bool operador();

#endif