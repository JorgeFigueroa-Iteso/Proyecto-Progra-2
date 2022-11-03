/* Branch - Ramón */
#include "eval.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

int main(void){

	char input[100];
	int i=0,n1=0,n2=0,n3=0;

	printf("Ingrese su ecuacion a evaluar: ");
	scanf("%s", input);
	printf("%s\n", input);


	/** 
	 * 
	 * Primero, cuando encuentre un ")", tengo que comprobar el/los operadores que hayan de pormedio 
	 * Para hacer eso, lo puedo hacer con un pop, sin embargo, tengo que agregarlo de una u otra forma a un stack, para hacer las operaciones
	 * 
	 * @TODO: hacer operaciones con el char
	 * 
	**/


	while(i!=strlen(input)) {
		if (input[i] == '(') {

			printf("Parentesis: %c\n", input[i]);
			stackPush(input[i]);

		} else if (input[i] == ')') {
			
			switch (stackPeek()){
				case '+': 
					stackPop();
					stackPop();
					n2 = queue_pop();
					queue_delete();
					n1=queue_pop();
					n3 = n1+n2;
					queue_insert(n3);
					queue_delete();
					printf("<-----	SUMA	----->\n");
					queue_size();
					printf("<-----	SUMA	----->\n");

					break;
				case '-': 
					printf("<-----	RESTA	----->\n");
					stackPop();					
					stackPop();
					n2 = queue_pop();
					queue_delete();
					n1=queue_pop();
					n3 = n1-n2;
					queue_insert(n3);
					queue_delete();
					printf("<-----	RESTA	----->\n");
					queue_size();
					printf("<-----	RESTA	----->\n");

					break;

				case '*': 
					printf("<-----	MULTI	----->\n");
					stackPop();					
					stackPop();
					n2 = queue_pop();
					queue_delete();
					n1=queue_pop();
					n3 = n1*n2;
					queue_insert(n3);
					queue_delete();
					printf("<-----	MULTI	----->\n");
					queue_size();
					printf("<-----	MULTI	----->\n");

					break;
				case '/':
					printf("<-----	DIV	----->\n");
					stackPop();					
					stackPop();
					n2 = queue_pop();
					queue_delete();
					n1=queue_pop();
					n3 = n1/n2;
					queue_insert(n3);
					queue_delete();
					printf("<-----	DIV	----->\n");
					queue_size();
					printf("<-----	DIV	----->\n");

					break;
				default: ("!!	 No operator	!!");
			}

		} else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {

			printf("Operador: %c\n", input[i]);
			stackPush(input[i]);

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

	stackPeek();

	do
	{
		if (stackisEmpty()==true){
			exit(0);
		} else {
			stackPop();
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
		    queue_insert(choice);							break;
		case 3: 
		    queue_delete();	
		    
		    break;
		case 4: 
		    queue_check();									break;
		case 5: 
		    queue_first_element();							break;
		case 6: 
		    queue_size();									break;
		default: 
		    printf("Opcion incorrecta\n");					break;
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