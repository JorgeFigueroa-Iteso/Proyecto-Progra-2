#include "eval.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>


/*      <------  VALIDACIÓN  ------>     */
// Creeditos a Axel, del curso de Programación de Memoria Dinámica, por facilitarme esta función.
bool isoperator(char input){
    switch (input){
        case '+':

        case '-':

        case '*':

        case '/':
            return true;
            break;
        default:
            return false;
            break;
       }
}

char* scanInput()
{
    char* input=NULL;
    // bool flag=false;
    size_t len=0;

    do {
        // Escanea el input del usuario
        printf("Expresion a evaluar: ");
        getline(&input, &len, stdin);
        for (size_t i = 0; i <= len; i++){
            if (input[i]=='\n'){
                // Finaliza la cadena, incertando '\0' al final de la cadena
                input[i]='\0';
            }
        }

        // Comienza la comparación de espacios

    } while (balanceo(input)!=true);



    return input;
}

bool balanceo(char* input){
    // printf("Expresion ingresada: %c\n", input);
    int b = 0, parD, parI, i, operat;
    parD = 1; parI = 1, i=0, operat=0;

    do{
        // printf("| %c |\n", input[i]);
        if (input[i]==' ') {
            ++b;
            printf("Se encontro un espacio/operador faltante.\n");
            break;
        } else if (isalpha(input[i]) == 1 || isalpha(input[i]) == 2) {
            ++b;
            printf("Se encontro un valor alfanumerico.\n");
            break;
        } else if (input[i] == '(') {
            ++parI;
            // printf("Par I\n");
        } else if (input[i] == ')' && input[i-1] != '(') {
            ++parD;

            // printf("Par D\n");
        } else if (i==0 && isoperator(input[i])==true) {
            printf("No se pude poner un operador al principio de la expresion.\n");
            ++b;
        }

        ++i;
    } while (input[i]!='\0');
 
    // Retorna true si no se encontró ningún error
    if (b==0 && (parD%parI)==0) {
        printf("\n");
        return true;
    } else {
        if ((parD%parI)!=0){
            printf("Error en los parentesis.\n");
        }
    }
}

/*      <------  VALIDACIÓN  ------>     */

/*      <------  STACK  ------>     */

struct NodeStack{
    Data data;
    struct NodeStack *prior;
};

typedef struct NodeStack * NodePS;

struct stack{
    NodePS top;
    size_t bytes;
    unsigned int size;
};

Stack stack_create(size_t bytes){
    Stack stk = malloc(sizeof(struct stack));
    stk->bytes=bytes;
    stk->size=0;
    stk->top=NULL;
    return stk;
}

int stack_size(Stack stk){
    if (stk!=NULL){
        return stk->size;
    } else {
        return -1;
    }
    
}

bool stack_isEmpty(Stack stk)
{
    if (stk != NULL)
    {
        if(stk->top==NULL){
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
    
}

Data stack_top(Stack stk)
{
    if (stk!=NULL)
    {
        if(stk->top!=NULL)
        {
            Data ret=malloc(stk->bytes);
            memcpy(ret, stk->top->data, stk->bytes);
            return ret;
        }
        else 
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

NodePS newNode(Data data, size_t bytes)
{
    NodePS new= malloc(sizeof(struct NodeStack));
    new->data=malloc(bytes);
    memcpy(new->data, data, bytes);
    new->prior=NULL;
    return new;
}

void stack_push(Stack stk, Data data)
{
    if(stk!=NULL)
    {
        NodePS nd=newNode(data, stk->bytes);
        stk->size++;
        nd->prior=stk->top;
        stk->top=nd;
    }
    else
    {
        printf("Error: Stack is null");
    }
}

Data stack_pop(Stack stk)
{
    if(stk!=NULL)
    {
        if(stk->top!=NULL)
        {
            void *dataTemp=stk->top->data;

            NodePS new_top=stk->top->prior;
            free(stk->top);
            stk->top=new_top;
            stk->size--;
            return dataTemp;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

void stack_destroy(Stack stk)
{
    if (stk!=NULL)
    {
        if(stk->top!=NULL && stk->size!=0)
        {
            for(int i=0; i<stk->size; i++)
            {
                if(stk->top!=NULL)
                {
                    NodePS next_node=stk->top->prior;
                    free(stk->top->data);
                    free(stk->top);
                    stk->top=next_node;
                }
            }
        }
        free(stk);
    }
}

/*      <------  STACK  ------>     */
