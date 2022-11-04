#include "eval.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;

void StackPush_B(char x) {
    stack[++top] = x;
}

char StackPop_B() {
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
    char input[100];
    char *ptr, x;
    printf("Expresion a evaluar : ");
    scanf("%s",input);
    printf("\n");
    ptr = input;

    Stack stk=stack_create(sizeof(double));

    while(*ptr != '\0') {
        double n,x10;

        if(isalnum(*ptr)){
            // Imprime los numeros
            printf("%c ",*ptr);

            n = atoi(ptr);
            // n = strtod(ptr, NULL);
            printf("double: %lf\n", n);
            stack_push(stk, &n);
            // stack_pop(stk);
            double* x10 = (double *)stack_top(stk);
            printf("%lf\n", x10);
            system("pause");

            // stackPush(*ptr);
        }
        else if(*ptr == '('){
            StackPush_B(*ptr);
        }
        else if(*ptr == ')') {
            while((x = StackPop_B()) != '('){
                float x1,x2,x3;
                char op;
                // Imprime el contenido de los paréntesis
                printf("%c ", x);

                double *pop1 = (double *)stack_pop(stk);
                double *pop2 = (double *)stack_pop(stk);
                Data x10 = stack_top(stk);

                printf(" ----------- %lf ---- %lf ---- %lf\n", &pop1, &pop2, x10);

                switch(x){
                    case '+':
                        printf("\n--SUMA--\n");
                        // x1 = stackPoped();
                        // x2 = stackPoped();
                        // stackPop();
                        x3 = x1+x2;
                        printf("x1: %.1f\nx2: %.1f\nx3: %.1f\n", x1,x2,x3);
                        // stackPush(x3);
                        system("pause");
                        break;
                    case '-':
                        printf("\n--RESTA--\n");
                        // x1 = stackPoped();

                        // x2 = stackPoped();
                        // stackPop();
                        x3 = x1-x2;
                        printf("x1: %.1f\nx2: %.1f\nx3: %.1f\n", x1,x2,x3);
                        // stackPush(x3);
                        system("pause");
                        break;
                    case '*':
                        printf("\n--MULTI--\n");
                        // x1 = stackPoped();

                        // x2 = stackPoped();
                        // stackPop();
                        x3 = x1*x2;
                        printf("x1: %.1f\nx2: %.1f\nx3: %.1f\n", x1,x2,x3);
                        // stackPush(x3);
                        system("pause");
                        break;
                    case '/':
                        printf("\n--DIV--\n");
                        // x1 = stackPoped();

                        // x2 = stackPoped();
                        // stackPop();
                        x3 = x2/x1;
                        printf("x1: %.1f\nx2: %.1f\nx3: %.1f\n", x1,x2,x3);
                        // stackPush(x3);
                        system("pause");
                        break;
                    default: printf("Awas we Awas\n");
                }

                printf("\nOperador: %c\n", x);
            }   
        }
        else {
            while(ordenJerarquico(stack[top]) >= ordenJerarquico(*ptr)){
                // Imprime los operadores con su orden respectivo
                char n = StackPop_B();
                printf("%c ", n);
            }
            StackPush_B(*ptr);
        }
        ptr++;
    }

    // stackPeek();

    /*  Resolver expresion NOTA.
    do {
        int x1 = stackPop();
        int x2 = stackPop();
        char op = queue_poped();
        queue_size();
        queue_delete();
        printf("Op: %c\n", op);
        printf("x1: %d\n", x1);
        printf("x2: %d\n", x2);
    } while (queue_check()!=false);
    queue_size();

    /*----------------------*/

    while(top != -1) {
        // Imprime lo que esta fuera de los paréntesis
        char n = StackPop_B();
        printf("%c ",n);

    }
}