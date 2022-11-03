#include "eval.h"

#include<stdio.h>
#include<ctype.h>
#include <stdlib.h>
#include <string.h>

char stack[100];
int top = -1;
/*
void stack_push(char x) {
    stack[++top] = x;
}

char stack_pop() {
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
*/

int ordenJerarquico(char x) {
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}


int main() {
    int j=0;

    char input[100];
    char *ptr, x;
    printf("Expresion a evaluar : ");
    scanf("%s",input);
    printf("\n");
    ptr = input;
    
    while(*ptr != '\0') {
        if(isalnum(*ptr)){
            // Imprime los numeros
            printf("%c ",*ptr);
            setArray(A, j, &ptr);
            ++j;
        }
        else if(*ptr == '('){
            stack_push(*ptr);
        }
        else if(*ptr == ')') {
            while((x = stack_pop()) != '('){
                // Imprime el contenido de los paréntesis
                printf("%c ", x);
                setArray(A, j, &x);
                ++j;
            }   
        }
        else {
            while(ordenJerarquico(stack[top]) >= ordenJerarquico(*ptr)){
                // Imprime los operadores con su orden respectivo
                char n = stack_pop();
                printf("%c ", n);
                setArray(A, j, &n);
                ++j;
            }
            stack_push(*ptr);
        }
        ptr++;
    }
    
    while(top != -1) {
        // Imprime lo que esta fuera de los paréntesis
        char n = stack_pop();
        printf("%c ",n);
        setArray(A, j, &n);
        ++j;
    }
}
