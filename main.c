/*Branch - joaquin*/

#include "eval.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h.h>

int main(void){
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
		    printf("\nQueue vacia creada.\n\n");	break;
		case 2:    
		    queue_insert();							break;
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
			case 1: stackPush(); parentesis();	break;
			case 2: stackPop();		break;
			case 3: stackPeek();	break;
			case 4: stackisEmpty(); break;

		}
	} while (1);

	return 0;
}

