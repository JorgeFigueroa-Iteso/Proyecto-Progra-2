#include "eval.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

/* Se grega una cadena tipo char para comparar el orden jerárquico */
char scanOrdenJerarquico[100];
int orden = -1;

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

    char *ptr, *x, numr;

    char* input=scanInput();

    printf("input: %s\n", input);
    system("pause");

    ptr = input;
    int pos = 0;

    /* <--- REPASO A CADENA ---> */

    while(*ptr != '\0') {
        double n,x10;
        // printf("Pasa primer ciclo while\n");

        if(isalnum(*ptr)){
            // Imprime los numeros
            printf("%c ",*ptr);

            int entero = *ptr-'0';
            double numd = entero;

            stack_push(stk, &numd);

            double* x10 = (double *)stack_top(stk);
        }
        else if(*ptr == '('){
            /* <--- Si se abre paréntesis lo agrega al stack ---> */
            stack_push(stk1, ptr);
        }
        else if(*ptr == ')') {
            x = stack_pop(stk1);
            while(*x != '('){
                char op;
                // Imprime el contenido de los paréntesis hasta que se cierre
                printf("%c ", *x);

                double *pop1 = NULL;
                double *pop2 = NULL;
                double *last = NULL;
                double res;

                switch(*x){
                    case '+':
                        /* <--- Caso SUMA ---> */
                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        res = ((*pop1)+(*pop2));
                        res = res;
                        
                        printf("", res);
                        stack_push(stk, &res);

                        break;
                    case '-':
                        /* <--- Caso RESTA ---> */
                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        res = (*pop2)-(*pop1);
                        printf("", res);
                        stack_push(stk, &res);

                        break;
                    case '*':
                        /* <--- Caso MULTIPLICACIÓN ---> */
                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        res = (*pop1)*(*pop2);
                        printf("", res);
                        stack_push(stk, &res);

                        break;
                    case '/':
                        /* <--- Caso DIVISIÓN ---> */
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
            while(ordenJerarquico(scanOrdenJerarquico[orden]) >= ordenJerarquico(*ptr)){
                // Imprime los operadores con su orden respectivo | Después del parentesis que se resolvió
                char *n = stack_pop(stk1);
                printf("%c ", *n);

                double *pop1 = NULL;
                double *pop2 = NULL;
                double *last = NULL;
                double res = 0;

                switch(*n){
                    case '+':
                        /* <--- Caso SUMA ---> */
                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        res = (*pop1)+(*pop2);
                        printf("", res);
                        stack_push(stk, &res);

                        break;
                    case '-':
                        /* <--- Caso RESTA ---> */
                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        res = (*pop2)-(*pop1);
                        printf("", res);
                        stack_push(stk, &res);

                        break;
                    case '*':
                        /* <--- Caso MULTIPLICACIÓN ---> */
                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        res = (*pop1)*(*pop2);
                        printf("", res);
                        stack_push(stk, &res);

                        break;
                    case '/':
                        /* <--- Caso DIVISIÓN ---> */
                        last=stack_top(stk);
                        pop1=stack_pop(stk);
                        pop2=stack_pop(stk);

                        res = (*pop2)/(*pop1);
                        printf("", res);
                        stack_push(stk, &res);

                        break;
                }   
            } /* Se agrega el operador al stack */ stack_push(stk1,ptr);
        } /* Se recorre el puntero que apunta a la operación */ ptr++;
    }

    /* En caso de que no se detecte ningún parentesis, se evalua sin el orden */
    while(stack_isEmpty(stk1) != true) {
        char *n = stack_pop(stk1);
        printf("%c ",*n);

        double *pop1 = NULL;
        double *pop2 = NULL;
        double *last = NULL;
        double res = 0;

        switch(*n){
            case '+':
                /* <--- Caso SUMA ---> */
                last=stack_top(stk);
                pop1=stack_pop(stk);
                pop2=stack_pop(stk);

                res = (*pop1)+(*pop2);
                printf("", res);
                stack_push(stk, &res);

                break;
            case '-':
                /* <--- Caso RESTA ---> */
                last=stack_top(stk);
                pop1=stack_pop(stk);
                pop2=stack_pop(stk);

                res = (*pop2)-(*pop1);
                printf("", res);
                stack_push(stk, &res);

                break;
            case '*':
                /* <--- Caso MULTIPLICACIÓN ---> */
                last=stack_top(stk);
                pop1=stack_pop(stk);
                pop2=stack_pop(stk);

                res = (*pop1)*(*pop2);
                printf("", res);
                stack_push(stk, &res);

                break;
            case '/':
                /* <--- Caso DIVISIÓN ---> */
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