#include "eval.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>



int main(void){

	nodeSTK st=stack_create(sizeof(char));

	char input[100];
	int i=0;

	printf("Ingrese su ecuacion a evaluar: ");
	scanf("%s", input);
	printf("%s\n", input);

	while(i!=strlen(input)) {
		if (input[i]=='(' || input[i] == ')') {

			printf("Parentesis: %c\n", input[i]);
			stack_push(st, input);

		} else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {

			printf("Operador: %c\n", input[i]);
			stack_push(st, input);

		} else {
			int ia = input[i] - '0';
			printf("Numero: %d\n", ia);

			queue_insert(ia);

		}
		i++;
	}

	printf("\nElementos del queue:\n");
	queue_size();

	printf("Primer elemento:\n");
	queue_first_element();

	printf("Elemento del stack\n");
	do
	{
		if (stack_isEmpty(st)==true){
			exit(0);
		} else {
			stack_pop(st);
		}
		
	} while (1);

/*
	// QUEUE FUNCIONAL
	int choice;
	do
	{
		printf("Seleccione opcion \n");
		printf("1 : Crear Queue \n2 : Insertar elemento\n");
		printf("3 : Dequeue un elemento \n4 : Verificar si esta vacio\n");
		printf("5 : Obtener el primer elemento del Queue\n");
		printf("6 : Ver los elementos del Queue\n");
		printf("0 : Exit\n");
		scanf("%d", &choice);
		switch (choice)    // menu driven program
		{
		case 0: 
		    exit(0);
		case 1: 
		    printf("\n<------  Queue creado  ------>\n\n");	break;
		case 2:    
		    queue_insert(input);							break;
		case 3: 
		    queue_delete();							break;
		case 4: 
		    queue_check();							break;
		case 5: 
		    queue_first_element();					break;
		case 6: 
		    queue_size();							break;
		default: 
		    printf("Opcion incorrecta\n");			break;
		}
	} while (1);
*/


/*
	// STACK FUNCIONAL
	int choice=0;
	do {
		system("cls");
		printf("Escoje una opcion:\n");
		// printf("\n0: Exit - 2: Pop - 4: Verificar si el stack esta vacio\n1: Push - 3: Peek");
		printf("1.- Push\n2.- Pop\n3.- Peek\n4.- Check\n0.- Exit\nOpcion: ");
		scanf("%d",&choice);
		switch(choice){
			case 0: exit(0);
			case 1: stackPush();	break;
			case 2: stackPop();		break;
			case 3: stackPeek();	break;
			case 4: stackisEmpty(); break;
		}
	} while (1);
*/	
	return 0;
}
