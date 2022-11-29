 #include "eval.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

int main(){
	char *in = NULL;
	size_t len = 0;

	Stack temp = stack_create(sizeof(char));
	Stack s1 = stack_create(sizeof(char));

	// in apunta a la cadena original.
	// in = malloc(20 * sizeof(char));
	// strcpy(in,"(3*(5/2)*2118)/2");
	getline(&in, &len, stdin);
	
	// cad es un espacio temporal para guardar cada elemento separado de la cadena original.
	char *cad;
	cad = malloc(20 * sizeof(char));

	char *pos, *tcad;
	pos=in; // Apuntar al inicio de la cadena
	char c;
	do{
		tcad=cad; // Posicionar al inicio de la memoria reservada para la cadena temporal
		do{
			c=*pos;
			*tcad = c;
			*tcad ++;
			*tcad = '\0';
			*pos++;
		}while((isdigit(c)==1)&&(isdigit(*pos)==1));
		
		if(*pos!='\0'){
			printf("CAD %s\n", cad);
			stack_push(temp, cad);
		}
	}while(c!='\0');

	do {
		char s[100];
		s = stack_pop(temp);
		printf("Stack Pop :: %c\n", *s);
	} while (stack_isEmpty(temp) != true);

	free(cad);
	free(in);
	return(0);
}