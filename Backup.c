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
    char *ptr, x, numr;
    printf("Expresion a evaluar : ");
    scanf("%s",input);
    printf("\n");
    ptr = input;
    int pos = 0;
    Stack stk=stack_create(sizeof(double));

    while(*ptr != '\0') {
        double n,x10;

        if(isalnum(*ptr)){
            // Imprime los numeros
            printf("[%c] ",*ptr);

            int entero = *ptr-'0';
            double numd = entero;

            // printf("double: %lf\n", numd);
            stack_push(stk, &numd);
            // stack_pop(stk);
            double* x10 = (double *)stack_top(stk);
            // printf("%f\n", *x10);
            // system("pause");
        }
        else if(*ptr == '('){
            StackPush_B(*ptr);
        }
        else if(*ptr == ')') {
            while((x = StackPop_B()) != '('){
                char op;
                // Imprime el contenido de los paréntesis
                printf("%c ", x);

                double *pop1 = NULL;
                double *pop2 = NULL;
                double res = 0;

                switch(x){
                    case '+':
                        printf("\n--SUMA--\n");

                        // double *pop1 = (double *)stack_pop(stk);
                        // double *pop2 = (double *)stack_pop(stk);

                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        printf("%f\n", *pop1);
                        printf("%f\n", *pop2);

                        res = *pop1+*pop2;
                        printf("%f\n", res);
                        stack_push(stk, &res);

                        printf("%f\n", stack_top(stk));

                        system("pause");
                        break;
                    case '-':
                        printf("\n--RESTA--\n");

                        system("pause");
                        break;
                    case '*':
                        printf("\n--MULTI--\n");

                        system("pause");
                        break;
                    case '/':
                        printf("\n--DIV--\n");

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
            if (pos<1) {
                /* Espera a que sea mayor a 0 */
                ++pos;
            } else {
                double *pop1 = NULL;
                double *pop2 = NULL;
                double res = 0;

                switch(*ptr){
                    case '+':
                        printf("\n--SUMA--\n");

                        // double *pop1 = (double *)stack_pop(stk);
                        // double *pop2 = (double *)stack_pop(stk);

                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        printf("%f\n", *pop1);
                        printf("%f\n", *pop2);

                        res = *pop1+*pop2;
                        printf("%f\n", res);
                        stack_push(stk, &res);

                        printf("%f\n", stack_top(stk));

                        system("pause");
                        break;
                    case '-':
                        printf("\n--RESTA--\n");

                        system("pause");
                        break;
                    case '*':
                        printf("\n--MULTI--\n");

                        system("pause");
                        break;
                    case '/':
                        printf("\n--DIV--\n");

                        system("pause");
                        break;
                    default: printf("Awas we Awas\n");
                }

                printf("\nOperador: %c\n", x);
            }

        } ptr++;
    }

/*    // stackPeek();

      Resolver expresion NOTA.
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
    queue_size();*/

    // ----------------------

    while(top != -1) {
        // Imprime lo que esta fuera de los paréntesis
        char n = StackPop_B();
        printf("%c ",n);

    }
}