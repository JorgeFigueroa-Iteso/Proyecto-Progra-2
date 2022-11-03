#include "Array.h"

#include<stdio.h>
#include<ctype.h>

char stack[100];
int top = -1;

void stackPush(char x) {
    stack[++top] = x;
}

char stackPop() {
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

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

    // A

    Array A=createArray(20, 4);
    int j=0;

    // int n=10;
    // setArray(A, 21, &n);
    // n=20;
    // setArray(A, -1, &n);
    // n=30;
    // setArray(A, -2, &n);
    // int *r;
    // for (int i=0;i<sizeArray(A); i++){
    //     r=getArray(A,i);
    //     printf(" %d ", *r);   
    // }

    // A



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
            stackPush(*ptr);
        }
        else if(*ptr == ')') {
            while((x = stackPop()) != '('){
                // Imprime el contenido de los paréntesis
                printf("%c ", x);
                setArray(A, j, &x);
                ++j;
            }   
        }
        else {
            while(ordenJerarquico(stack[top]) >= ordenJerarquico(*ptr)){
                // Imprime los operadores con su orden respectivo
                char n = stackPop();
                printf("%c ", n);
                setArray(A, j, &n);
                ++j;
            }
            stackPush(*ptr);
        }
        ptr++;
    }
    
    while(top != -1) {
        // Imprime lo que esta fuera de los paréntesis
        char n = stackPop();
        printf("%c ",n);
        setArray(A, j, &n);
        ++j;

    }

    printf("Array\n");
    int *r;
    for (int i=0;i<sizeArray(A); i++){
        r=getArray(A,i);
        printf(" %d ", *r);
    }return 0;
}