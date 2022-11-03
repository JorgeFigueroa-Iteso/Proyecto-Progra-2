#include "eval.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/*      <------  STACK  ------>     */

struct Node_Stack{
    char val;
    struct Node_Stack *next;
};

struct Node_Stack *head;

void stackPush(float input){
    struct Node_Stack *ptr = (struct Node_Stack*)malloc(sizeof(struct Node_Stack));
    float val = input;
    // printf("Valor a almacenar en el stack: ");
    // scanf("%d", &val);

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

void stackPop(){
    float item;
    struct Node_Stack *ptr;
    if (head!=NULL) {
        item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);
        float ia = item - '0';
        printf("\n%.1f fue liberado del stack\n", ia);
        // system("timeout /t 3");
        printf("Numero: %d\n", ia);
        // return ia;
    } else {
        printf("<------  No hay elementos en el Stack  ------>\n");
    }
    // system("timeout /t 3");
}

float stackPoped(){
    float item;
    struct Node_Stack *ptr;
    if (head!=NULL) {
        item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);
        float ia = item - '0';
        // printf("\n%.1f fue liberado del stack\n", ia);
        // system("timeout /t 3");
        // printf("Numero: %d\n", ia);
        return ia;
    } else {
        // printf("<------  No hay elementos en el Stack  ------>\n");
    }
    // system("timeout /t 3");
}


float stackPeek(){
    if (head!=NULL){
        float x = head->val;
        printf("\n%.1f es el ultimo valor que tiene el Stack\n", x);
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




/*      <------  QUEUE  ------>     */

struct Node_Queue
{
    char data;
    struct Node_Queue *link;
}*front, *rear;

void queue_insert(char input)
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
        printf("<------  Elemento eliminado: %c  ------>\n\n", front->data);
        front = front->link;
        free(temp);
    }
    // system("timeout /t 3");
}

float queue_poped()
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
        printf("<------  Elemento eliminado: %.1f  ------>\n\n", front->data);
        return front->data;
        front = front->link;
        free(temp);
    }
    // system("timeout /t 3");
}

// check if queue is empty or not
bool queue_check()
{
    if (front == NULL){
        printf("\nQueue esta vacio\n");
        return false;
    }
    else{
        printf("<------  Hay elementos en el queue  ------>\n\n");
        return true;
    }
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
        printf("<------  Elemento frontal es: %c  ------>\n\n", front->data);
    // system("timeout /t 3");
}

// returns number of entries and displays the elements in queue
char queue_size()
{
    struct Node_Queue *temp;

    temp = front;
    int cnt = 0;
    if (front  ==  NULL) {
        printf("<------  Queue esta vacio  ------>\n\n");
        return 0;
    } else {
        printf("\n<------ ");
        while (temp)
        {
            printf("| %2c ", temp->data);
            temp = temp->link;
            cnt++;
        }
        printf(" | tamano del queue es: %d  ------>\n\n", cnt);
        return cnt;
    }
    // system("timeout /t 3");
}