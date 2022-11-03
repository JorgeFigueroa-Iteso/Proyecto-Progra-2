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
    char input[100];
    char *ptr, x;
    printf("Expresion a evaluar : ");
    scanf("%s",input);
    printf("\n");
    ptr = input;
    
    while(*ptr != '\0') {
        if(isalnum(*ptr))
            printf("%c ",*ptr);
        else if(*ptr == '(')
            stackPush(*ptr);
        else if(*ptr == ')') {
            while((x = stackPop()) != '(')
                printf("%c ", x);
        }
        else {
            while(ordenJerarquico(stack[top]) >= ordenJerarquico(*ptr))
                printf("%c ",stackPop());
            stackPush(*ptr);
        }
        ptr++;
    }
    
    while(top != -1) {
        printf("%c ",stackPop());
    }return 0;
}