#include "eval.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	// Stack s1 = stack_create(sizeof(double));
	printf("Se creo el stack de forma correcta\n");

    char c2 = '1';
    char c1 = '2';
    char *c3, *pos, fin[100];
    printf("Se crean las variables\n");

    c3[0] = '1';
    c3[1] = '2';
    // c3[2] = '\0';
    printf("Se agregan los valores que se van a modificar a c3\n");

    fin[0] = c3;
    printf("Cosa wea weon wonada: %c\n", fin[0]);

    double d = strtol(c3, &pos, 10);
    printf("Se hace el cast a: %.2f\n", d);

    // stack_push(s1,&d);
    // printf("Push al stack\n");

    // double* a = stack_pop(s1);
    // printf("pop al stack\nResultado: %.2f", &a);

	return 0;
}