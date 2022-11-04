#include "eval.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/*      <------  STACK  ------>     */

struct NodeStack{
    Data data;
    struct NodeStack *prior;
};

typedef struct NodeStack * NodePS;

struct stack{
    NodePS top;
    size_t bytes;
    unsigned int size;
};

Stack stack_create(size_t bytes){
    Stack stk = malloc(sizeof(struct stack));
    stk->bytes=bytes;
    stk->size=0;
    stk->top=NULL;
    return stk;
}

int stack_size(Stack stk){
    if (stk!=NULL){
        return stk->size;
    } else {
        return -1;
    }
    
}

bool stack_isEmpty(Stack stk)
{
    if (stk != NULL)
    {
        if(stk->top==NULL){
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

Data stack_top(Stack stk)
{
    if (stk!=NULL)
    {
        if(stk->top!=NULL)
        {
            Data ret=malloc(stk->bytes);
            memcpy(ret, stk->top->data, stk->bytes);
            return ret;
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

NodePS newNode(Data data, size_t bytes)
{
    NodePS new= malloc(sizeof(struct NodeStack));
    new->data=malloc(bytes);
    memcpy(new->data, data, bytes);
    new->prior=NULL;
    return new;
}

void stack_push(Stack stk, Data data)
{
    if(stk!=NULL)
    {
        NodePS nd=newNode(data, stk->bytes);
        stk->size++;
        nd->prior=stk->top;
        stk->top=nd;
    }
    else
    {
        printf("Error: Stack is null");
    }
}

Data stack_pop(Stack stk)
{
    if(stk!=NULL)
    {
        if(stk->top!=NULL)
        {
            void *dataTemp=stk->top->data;

            NodePS new_top=stk->top->prior;
            free(stk->top);
            stk->top=new_top;
            stk->size--;
            return dataTemp;
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

void stack_destroy(Stack stk)
{
    if (stk!=NULL)
    {
        if(stk->top!=NULL && stk->size!=0)
        {
            for(int i=0; i<stk->size; i++)
            {
                if(stk->top!=NULL)
                {
                    NodePS next_node=stk->top->prior;
                    free(stk->top->data);
                    free(stk->top);
                    stk->top=next_node;
                }
            }
        }
        free(stk);
    }
}