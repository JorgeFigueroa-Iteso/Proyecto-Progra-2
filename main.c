#include "eval.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	Stack s1 = stack_create(sizeof(double));

	char input[100], *ptr;
	input[0] = '1';
	ptr = input;
	char num1 = *ptr;


	int entero = *ptr-'0';
	printf("%d\n", entero);

	double n = entero;
	
	printf("%f\n", n);

	for (int i = 0; i < 5; ++i)
	{
		stack_push(s1, &n);
		n=n+1;
	}

	double *num = NULL;
	for (int j = 0; j < 5; ++j)
	{
		num=stack_pop(s1);
		printf("%f\n", *num);
	}


	return 0;
}