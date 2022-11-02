#include "eval.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/*	<--- Comienzo de operaciones desde el .h --->	*/

struct Node{
	int val;
	struct Node *next;
};

struct Node *head;

void stackPush(){
	int val;
	struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
	printf("Valor a almacenar en el stack: ");
	scanf("%s", &val);

	if (head == NULL){
		ptr->val = val;
		ptr->next= NULL;
		head = ptr;
	} else{
		ptr->val = val;
		ptr->next= head;
		head=ptr;
	}
	system("timeout /t 3");
}

int stackPop(){
	int item;
	struct Node *ptr;
	if (head!=NULL) {
		item = head->val;
		ptr = head;
		head = head->next;
		free(ptr);
		printf("%c fue liberado del stack", item);
		system("timeout /t 3");
		return item;
	} else {
		printf("No hay elementos en el Stack");
	}
	system("timeout /t 3");
}


int stackPeek(){
	if (head!=NULL){
	    int x = head->val;
	    printf("%c es el ultimo valor que tiene el Stack\n", x);
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


