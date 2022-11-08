#include "eval.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

char scanOrdenJerarquico[100];
int top = -1;

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
    
    Stack stk =stack_create(sizeof(double));
    Stack stk1=stack_create(sizeof(char));

    char input[100];
    char *ptr, *x, numr;
    printf("Expresion a evaluar : ");
    scanf("%s",input);
    printf("\n");
    ptr = input;
    int pos = 0;


    while(*ptr != '\0') {
        double n,x10;

        if(isalnum(*ptr)){
            // Imprime los numeros
            printf("%c ",*ptr);

            int entero = *ptr-'0';
            double numd = entero;

            stack_push(stk, &numd);

            double* x10 = (double *)stack_top(stk);
        }
        else if(*ptr == '('){
            stack_push(stk1, ptr);
        }
        else if(*ptr == ')') {
            x = stack_pop(stk1);
            while(*x != '('){
                char op;
                // Imprime el contenido de los paréntesis
                printf("%c ", *x);

                double *pop1 = NULL;
                double *pop2 = NULL;
                double *last = NULL;
                double res;

                switch(*x){
                    case '+':
                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        res = ((*pop1)+(*pop2));
                        res = res;
                        
                        printf("", res);
                        stack_push(stk, &res);

                        break;
                    case '-':
                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        res = (*pop2)-(*pop1);
                        printf("", res);
                        stack_push(stk, &res);

                        break;
                    case '*':
                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        res = (*pop1)*(*pop2);
                        printf("", res);
                        stack_push(stk, &res);

                        break;
                    case '/':
                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        res = (*pop2)/(*pop1);
                        printf("", res);
                        stack_push(stk, &res);

                        break;
                }
                x = stack_pop(stk1);
            }   
        }
        else {
            while(ordenJerarquico(scanOrdenJerarquico[top]) >= ordenJerarquico(*ptr)){
                // Imprime los operadores con su orden respectivo
                char *n = stack_pop(stk1);
                printf("%c ", *n);

                double *pop1 = NULL;
                double *pop2 = NULL;
                double *last = NULL;
                double res = 0;

                switch(*n){
                    case '+':
                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        res = (*pop1)+(*pop2);
                        printf("", res);
                        stack_push(stk, &res);

                        break;
                    case '-':
                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        res = (*pop2)-(*pop1);
                        printf("", res);
                        stack_push(stk, &res);

                        break;
                    case '*':
                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        res = (*pop1)*(*pop2);
                        printf("", res);
                        stack_push(stk, &res);

                        break;
                    case '/':
                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        res = (*pop2)/(*pop1);
                        printf("", res);
                        stack_push(stk, &res);

                        break;
                }   
            } stack_push(stk1,ptr);
        } ptr++;
    }

    while(stack_isEmpty(stk1) != true) {
        char *n = stack_pop(stk1);
        printf("%c ",*n);

        double *pop1 = NULL;
        double *pop2 = NULL;
        double *last = NULL;
        double res = 0;

        switch(*n){
            case '+':
                last=stack_top(stk);
                pop1=stack_pop(stk);
                pop2=stack_pop(stk);

                res = (*pop1)+(*pop2);
                printf("", res);
                stack_push(stk, &res);

                break;
            case '-':
                last=stack_top(stk);
                pop1=stack_pop(stk);
                pop2=stack_pop(stk);

                res = (*pop2)-(*pop1);
                printf("", res);
                stack_push(stk, &res);

                break;
            case '*':
                last=stack_top(stk);
                pop1=stack_pop(stk);
                pop2=stack_pop(stk);

                res = (*pop1)*(*pop2);
                printf("", res);
                stack_push(stk, &res);

                break;
            case '/':
                last=stack_top(stk);
                pop1=stack_pop(stk);
                pop2=stack_pop(stk);

                res = (*pop2)/(*pop1);
                printf("", res);
                stack_push(stk, &res);

                break;
        }   
    }   
    printf("\nResultado: %f\n", stack_top(stk));
}