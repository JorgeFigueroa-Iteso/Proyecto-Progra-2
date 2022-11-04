#include "eval.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * newInt(int valor){
	int *new=malloc(sizeof(int));
	*new=valor;
	return new;
}

int main(){

	Stack s1=stack_create(sizeof(int));
	printf("s1: %p\n", s1);
	printf("Size s1: %d\n", stack_size(s1));
	int n=0;
	stack_push(s1, &n);

	n=10;
	stack_push(s1, &n);
	n=40;
	stack_push(s1, &n);
	printf("Size s1: %d\n", stack_size(s1));

	int * dato;
	dato=stack_top(s1);
	printf("Top s1: %d\n", *dato);

	while(!stack_isEmpty(s1)){
		dato=stack_pop(s1);
		printf("Pop s1: %d\n", *dato);
	}

	// dato=stack_pop(s1);

	printf("Top s1: %d\n", *dato);
	// system("pause");
	return 0;
}