/* Branch - Ramón */
#include "eval.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

struct Node_Stack{
	char val;
	struct Node_Stack *next;
};

int main(void){

	char input[100];
	int i=0;

	printf("Ingrese su ecuacion a evaluar: ");
	scanf("%s", input);
	printf("%s\n", input);

	while(i!=strlen(input)) {
		int ia;
		char peek = stackPeek();
		switch (input[i]){
			case '(':
				system("pause");
				stackPush(input[i]);

				break;
			case ')':
				system("pause");
				stackPush(input[i]);

				break;
			case '+':
				printf("peek: %c\ninput: %c", peek,input[i]);
				system("pause");
				
				break;
			case '-':
				printf("peek: %c\ninput: %c", peek,input[i]);
				system("pause");
				
				break;
			case '*':
				printf("peek: %c\ninput: %c", peek,input[i]);
				system("pause");
				

				break;
			case '/':
				printf("peek: %c\ninput: %c", peek,input[i]);
				system("pause");
				

				break;
			default:
				ia = input[i] - '0';
				queue_insert(ia);
				break;
		}
		/*if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') 
		{
			char peek = stackPeek();
			switch(input[i]){
				case '+':
					if (peek =='-'){
						stackPop();
						stackPush(input[i]);
						stackPush('-');
					} else if (peek =='*'){
						stackPop();
						stackPop();
						stackPush(input[i]);
						stackPop();
						stackPop();
						stackPush('*');
					} else if (peek =='/'){
						stackPop();
						stackPush(input[i]);
						stackPush('/');
					} else{
						stackPush(input[i]);
					}
					break;
				case '-':
					if (peek =='+'){
						stackPop();
						stackPush('+');
						stackPush(input[i]);
					} else if (peek =='*'){
						stackPop();
						stackPush('*');
						stackPush(input[i]);
					} else if (peek =='/'){
						stackPop();
						stackPush('/');
						stackPush(input[i]);
					} else{
						stackPush(input[i]);
					}
					break;
				case '*':
					if (peek =='/'){
						stackPop();
						stackPush('/');
						stackPush(input[i]);
					} else{
						stackPush(input[i]);
					}
					break;
				case '/':
					 if (peek =='*'){
						stackPop();
						stackPush('*');
						stackPush(input[i]);
					} else{
						stackPush(input[i]);
					}
					break;
					
			}

			// printf("Operador: %c\n", input[i]);
			// stackPush(input[i]);

		} else {
			int ia = input[i] - '0';
			printf("Numero: %d\n", ia);

			queue_insert(ia);

		}*/
		i++;
	}

	printf("\nElementos del queue:\n");
	queue_size();
	int k=0;
	do{
		int x = queue_poped();
		queue_pop();
		queue_insert(x);
		++k;
	} while (k<queue_size()/2);

	i=0;
	do{
		int x2 = queue_poped();
		printf("%d\n", x2);
		queue_pop();
		int x1 = queue_poped();
		printf("%d\n", x1);
		queue_pop();
		int x3=0;
		char top = stackPeek();
		// while(top=='(' || top==')'){
		// 	stackPop();
		// }
		switch(top){
			case '+':
				x3 = (x1+x2);
				printf("<----SUMA %d\n", x3);
				queue_insert(x3);
				stackPop();
				stackPop();
				break;
			case '-':
				x3 = (x1-x2);
				printf("<----RESTA %d\n", x3);
				queue_insert(x3);
				stackPop();
				stackPop();
				break;
			case '*':
				x3 = (x1*x2);
				printf("<----MULTI %d\n", x3);
				queue_insert(x3);
				stackPop();
				stackPop();
				break;
			case '/':
				x3 = (double)(x2/x1);
				printf("<----DIV %d\n", x3);
				queue_insert(x3);
				stackPop();
				stackPop();
				break;
			default:
				printf("NO JALA EL FILTRO!\n"); break;
		}
		++i;
	} while (i<queue_size());

	printf("aaaaaaaaaaaaa\n");
	queue_size();

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