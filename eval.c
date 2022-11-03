#include "eval.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

/*      <------  STACK  ------>     */
/*
struct Node_Stack{
    char val;
    struct Node_Stack *next;
};

struct Node_Stack *head;

void stackPush(char input){
    char val;
    struct Node_Stack *ptr = (struct Node_Stack*)malloc(sizeof(struct Node_Stack));
    // printf("Valor a almacenar en el stack: ");
    // scanf("%d", &val);
    val = input;

    if (head == NULL){
        ptr->val = val;
        ptr->next= NULL;
        head = ptr;
    } else{
        ptr->val = val;
        ptr->next= head;
        head=ptr;
    }
    // system("timeout /t 3");
}

int stackPop(){
    int item;
    struct Node_Stack *ptr;
    if (head!=NULL) {
        item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("%c fue liberado del stack\n", item);
        // system("timeout /t 3");
        return item;
    } else {
        printf("<------  No hay elementos en el Stack  ------>\n");
    }
    // system("timeout /t 3");
}


int stackPeek(){
    if (head!=NULL){
        int x = head->val;
        printf("%c es el ultimo valor que tiene el Stack\n", x);
        // system("timeout /t 3");
        return x;
    } else {
        printf("<------  Stack vacio  ------>\n");
    }
    // system("timeout /t 3");
}

bool stackisEmpty(){
    if(head == NULL){
        printf("Stack vacio\n");
        // system("timeout /t 3");
        return true;
    }
    printf("Stack contiene elementos\n");
    // system("timeout /t 3");
    return false;
}
*/

struct nodeSTK
{
    DATA data;
    struct nodeSTK *prior;

};
    //POinter to node of stack
typedef struct nodeSTK * NodePS;

    //Container stack
struct stack
{
    NodePS top;
    int size;
    size_t bytes;
};

Stack stack_create(size_t bytes)
{
    //Memory for all the elements in the struct stack
    Stack stk= malloc(sizeof(struct stack));

    //Initialize in 0
    stk->bytes=bytes;
    stk->size=0;
    stk->top=NULL;
    return stk;

}

int stack_size(Stack stk)
{
    if (stk!=NULL)
    {
        return stk->size;
    }
    else
    {
        return -1;
    }
    
}

bool stack_isEmpty(Stack stk)
{
    if (stk != NULL)
    {
        if(stk->top==NULL)
        {
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

DATA stack_top(Stack stk)
{
    if (stk!=NULL)
    {
        if(stk->top!=NULL)
        {
            DATA ret=malloc(stk->bytes);
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

NodePS newNode(DATA data, size_t bytes)
{
    NodePS new= malloc(sizeof(struct nodeSTK));
    new->data=malloc(bytes);
    memcpy(new->data, data, bytes);
    new->prior=NULL;
    return new;
}

void stack_push(Stack stk, DATA data)
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

DATA stack_pop(Stack stk)
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

    // Destroy nodes

    if (stk!=NULL)
    {
        if(stk->top!=NULL && stk->size!=0)
        {
            for(int i=0; i<stk->size; i++)
            {
                // Save next node to destroy
                if(stk->top!=NULL)
                {
                    NodePS next_node=stk->top->prior;
                    //Destroy one at the top
                    free(stk->top->data);
                    free(stk->top);

                    //Make new top
                    stk->top=next_node;
                }
            }
        }
        //Delete stack
        free(stk);
    }
}




/*      <------  QUEUE  ------>     */

struct Node_Queue
{
    int data;
    struct Node_Queue *link;
}*front, *rear;

void queue_insert(int input)
{
    struct Node_Queue *temp;

    temp = (struct Node_Queue*)malloc(sizeof(struct Node_Queue));
    // printf("Inserte el valor: \n");
    // scanf("%d", &temp->data);
    temp->data = input;
    temp->link = NULL;
    if (rear  ==  NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
    }
    // system("timeout /t 3");
}

// delete elements from queue
void queue_delete()
{
    struct Node_Queue *temp;

    temp = front;
    if (front == NULL)
    {
        printf("<------  Queue vacio  ------>\n\n");
        front = rear = NULL;
    }
    else
    {
        printf("<------  Elemento eliminado: %d------>\n\n", front->data);
        front = front->link;
        free(temp);
    }
    // system("timeout /t 3");
}

int queue_pop()
{
    struct Node_Queue *temp;

    temp = front;
    if (front == NULL)
    {
        printf("<------  Queue vacio  ------>\n\n");
        front = rear = NULL;
    }
    else
    {
        printf("<------  Elemento eliminado: %d------>\n\n", front->data);
        return front->data;
        front = front->link;
        free(temp);
    }
    // system("timeout /t 3");
}

// check if queue is empty or not
void queue_check()
{
    if (front == NULL)
        printf("\nQueue esta vacio\n");
    else
        printf("<------  Hay elementos en el queue  ------>\n\n");
    // system("timeout /t 3");
}

// returns first element of queue
void queue_first_element()
{
    if (front == NULL)
    {
        printf("<------  Queue esta vacio  ------>\n\n");
    }
    else
        printf("<------  Elemento frontal es: %d  ------>\n\n", front->data);
    // system("timeout /t 3");
}

// returns number of entries and displays the elements in queue
void queue_size()
{
    struct Node_Queue *temp;

    temp = front;
    int cnt = 0;
    if (front  ==  NULL) {
        printf("<------  Queue esta vacio  ------>\n\n");
    } else {
        printf("<------ ");
        while (temp)
        {
            printf("| %2d ", temp->data);
            temp = temp->link;
            cnt++;
        }
        printf(" | tamano del queue es: %d  ------>\n\n", cnt);
    }
    // system("timeout /t 3");
}

