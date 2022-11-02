#include "eval.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
/*	<--- Comienzo de operaciones desde el .h --->	*/

/*		<------  STACK  ------>		*/

struct Node_Stack{
	int val;
	struct Node_Stack *next;
};

struct Node_Stack *head;

void stackPush(){
	int val;
	struct Node_Stack *ptr = (struct Node_Stack*)malloc(sizeof(struct Node_Stack));
	printf("Valor a almacenar en el stack: ");
	scanf("%d", &val);

	if (head == NULL){
		ptr->val = val;
		ptr->next= NULL;
		head = ptr;
	} else{
		ptr->val = val;
		ptr->next= head;
		head=ptr;

int stackPop(){
	int item;
	struct Node_Stack *ptr;
	if (head!=NULL) {
		item = head->val;
		ptr = head;
		head = head->next;
		free(ptr);
		printf("%d fue liberado del stack\n", item);
		system("timeout /t 3");
		return item;
	} else {
		printf("No hay elementos en el Stack\n");
	}
	system("timeout /t 3");
}


int stackPeek(){
	if (head!=NULL){
	    int x = head->val;
	    printf("%d es el ultimo valor que tiene el Stack\n", x);
		system("timeout /t 3");
	    return x;
	} else {
		printf("El Stack esta vacio.\n");
	}
	system("timeout /t 3");
}

bool stackisEmpty(){
	if(head == NULL){
        printf("Stack vacio\n");
		system("timeout /t 3");
        return true;
    }
    printf("Stack contiene elementos\n");
	system("timeout /t 3");
    return false;
}




/*		<------  QUEUE  ------>		*/

struct Node_Queue
{
    int data;
    struct Node_Queue *link;
}*front, *rear;

void queue_insert()
{
    struct Node_Queue *temp;
 
    temp = (struct Node_Queue*)malloc(sizeof(struct Node_Queue));
    printf("Inserte el valor: \n");
    scanf("%d", &temp->data);
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
	system("timeout /t 3");
}
 
// delete elements from queue
void queue_delete()
{
    struct Node_Queue *temp;
 
    temp = front;
    if (front == NULL)
    {
        printf("Queue esta vacio\n");
        front = rear = NULL;
    }
    else
    {    
        printf("Elemento eliminado: %d\n", front->data);
        front = front->link;
        free(temp);
    }
    system("timeout /t 3");
}
 
// check if queue is empty or not
void queue_check()
{
    if (front == NULL)
        printf("\nQueue esta vacio\n");
    else
        printf("*************** Hay elementos en el queue **************\n");
    system("timeout /t 3");
}
 
// returns first element of queue
void queue_first_element()
{
    if (front == NULL)
    {
        printf("**************** Queue esta vacio ****************\n");
    }
    else
        printf("**************** El elemento frontall es: %d ***********\n", front->data);        
    system("timeout /t 3");
}
 
// returns number of entries and displays the elements in queue
void queue_size()
{
    struct Node_Queue *temp;
 
    temp = front;
    int cnt = 0;
    if (front  ==  NULL)
    {
        printf(" Queue vacia \n");
    }
    while (temp)
    {
        printf("%d  ", temp->data);
        temp = temp->link;
        cnt++;
    }
    printf("********* tamano del queue es: %d ******** \n", cnt);
    system("timeout /t 3");
}


bool parentesis(opdr pss){
    Stack st=malloc(sizeof(struct Node_Stack));
    int i=0;

    while(pss[i]!="\0"){
        if(pss[i]=="("){
            stackPush(st, &pss[i]);
        }
        else if (pss[i]==")"){
            if (stackPop(st)==NULL){
                printf("parentecis incompleto\nincorrecto.\n");
                return false;
            }
        }
        i++
    }
    if (stackisEmpty(st)){
        return true;
    }
    else{
        printf("parentecis incompleto\nincorrecto.\n");
        return false;  
    }
}


