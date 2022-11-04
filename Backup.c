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
            printf("%c ",*ptr);

            int entero = *ptr-'0';
            double numd = entero;

            stack_push(stk, &numd);

            double* x10 = (double *)stack_top(stk);
            // printf("%f\n", *x10);
            system("pause");
        }
        else if(*ptr == '('){
            StackPush_B(*ptr);
        }
        else if(*ptr == ')') {
            while((x = StackPop_B()) != '('){
                char op;
                // Imprime el contenido de los paréntesis
                printf("%c Dentro de los PARENTESIS", x);

                double *pop1 = NULL;
                double *pop2 = NULL;
                double *last = NULL;
                double res = 0;

                switch(x){
                    case '+':
                        // printf("\n--SUMA--\n");

                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        // printf("%f\n", *pop1);
                        // printf("%f\n", *pop2);

                        res = (*pop1)+(*pop2);
                        printf("\n%f\n", res);
                        stack_push(stk, &res);


                        system("pause");
                        break;
                    case '-':
                        // printf("\n--RESTA--\n");

                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        // printf("%f\n", *pop1);
                        // printf("%f\n", *pop2);

                        res = (*pop2)-(*pop1);
                        printf("\n%f\n", res);
                        stack_push(stk, &res);


                        system("pause");
                        break;
                    case '*':
                        printf("\n--MULTI--\n");

                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        // printf("%f\n", *pop1);
                        // printf("%f\n", *pop2);

                        res = (*pop1)*(*pop2);
                        printf("\n%f\n", res);
                        stack_push(stk, &res);


                        system("pause");
                        break;
                    case '/':
                        printf("\n--DIV--\n");

                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        // printf("%f\n", *pop1);
                        // printf("%f\n", *pop2);

                        res = (*pop2)/(*pop1);
                        printf("\n%f\n", res);
                        stack_push(stk, &res);


                        system("pause");
                        break;
                    // default: printf("Error\n");
                }

                // printf("\nOperador: %c\n", x);
            }   
        }
        else {
            while(ordenJerarquico(stack[top]) >= ordenJerarquico(*ptr)){
                // Imprime los operadores con su orden respectivo
                char n = StackPop_B();
                printf("%c | FUERA DE PARENTESIS!", n);

                double *pop1 = NULL;
                double *pop2 = NULL;
                double *last = NULL;
                double res = 0;

                switch(n){
                    case '+':
                        // printf("\n--SUMA--\n");

                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        // printf("%f\n", *pop1);
                        // printf("%f\n", *pop2);

                        res = (*pop1)+(*pop2);
                        printf("\n%f\n", res);
                        stack_push(stk, &res);


                        system("pause");
                        break;
                    case '-':
                        // printf("\n--RESTA--\n");

                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        // printf("%f\n", *pop1);
                        // printf("%f\n", *pop2);

                        res = (*pop2)-(*pop1);
                        printf("\n%f\n", res);
                        stack_push(stk, &res);


                        system("pause");
                        break;
                    case '*':
                        // printf("\n--MULTI--\n");

                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        // printf("%f\n", *pop1);
                        // printf("%f\n", *pop2);

                        res = (*pop1)*(*pop2);
                        printf("\n%f\n", res);
                        stack_push(stk, &res);


                        system("pause");
                        break;
                    case '/':
                        // printf("\n--DIV--\n");

                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        // printf("%f\n", *pop1);
                        // printf("%f\n", *pop2);

                        res = (*pop2)/(*pop1);
                        printf("\n%f\n", res);
                        stack_push(stk, &res);


                        system("pause");
                        break;
                    // default: printf("Error\n");
                }   
                // printf("\nOperador: %c\n", x);
                // system("pause");
            }
            StackPush_B(*ptr);
        } ptr++;
    }
    // stack_pop(stk);
    // printf("%f\n", stack_top(stk));

    while(top != -1) {
        // Imprime el fin
        char n = StackPop_B();
        printf("%c UsoNormal",n);
        // system("pause");
        double *pop1 = NULL;
        double *pop2 = NULL;
        double *last = NULL;
        double res = 0;

        switch(n){
            case '+':
                // printf("\n--SUMA--\n");

                last=stack_top(stk);
                pop1=stack_pop(stk);
                pop2=stack_pop(stk);

                // printf("%f\n", *pop1);
                // printf("%f\n", *pop2);

                res = (*pop1)+(*pop2);
                printf("\n%f\n", res);
                stack_push(stk, &res);


                system("pause");
                break;
            case '-':
                // printf("\n--RESTA--\n");

                last=stack_top(stk);
                pop1=stack_pop(stk);
                pop2=stack_pop(stk);

                // printf("%f\n", *pop1);
                // printf("%f\n", *pop2);

                res = (*pop2)-(*pop1);
                printf("\n%f\n", res);
                stack_push(stk, &res);


                system("pause");
                break;
            case '*':
                // printf("\n--MULTI--\n");

                last=stack_top(stk);
                pop1=stack_pop(stk);
                pop2=stack_pop(stk);

                // printf("%f\n", *pop1);
                // printf("%f\n", *pop2);

                res = (*pop1)*(*pop2);
                printf("\n%f\n", res);
                stack_push(stk, &res);


                system("pause");
                break;
            case '/':
                // printf("\n--DIV--\n");

                last=stack_top(stk);
                pop1=stack_pop(stk);
                pop2=stack_pop(stk);

                // printf("%f\n", *pop1);
                // printf("%f\n", *pop2);

                res = (*pop2)/(*pop1);
                printf("\n%f\n", res);
                stack_push(stk, &res);


                system("pause");
                break;
            // default: printf("Error\n");
        }   
        // printf("\nOperador: %c\n", x);
    }   
    printf("\nUltimo elemento: %f\n", stack_top(stk));
}