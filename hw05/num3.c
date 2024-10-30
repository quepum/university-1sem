#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "stack.h"
#include "testsForStack.h"

#define SIZE 101


int rangOfOperand(const char operand){
    int rang = 0;
    switch (operand) {
        case '(':
            rang = 1;
            break;
        case '+':
        case '-':
            rang = 2;
            break;
        case '*':
        case '/':
            rang = 3;
            break;
        default:
            break;
    }
    return rang;
}


Element* fromInfixToPostfix(const char expression[]){
    Element* draftVersion = NULL;
    Element* auxiliary = NULL;
    int size = (int) strlen(expression);

    for (int i = 0; i < size; ++i){
        switch (expression[i]) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '(':
                auxiliary = push(auxiliary, expression[i]);
                printf("Кладу в стек операций %c\n", auxiliary->value);
                int rangCurrentOperand = rangOfOperand(expression[i]);
                while (rangOfOperand(auxiliary->value) > rangCurrentOperand){
                    draftVersion = push(draftVersion,auxiliary->value);
                    auxiliary = pop(auxiliary);
                }
                break;
            case ')':
                while (peek(auxiliary) != '('){
                    draftVersion = push(draftVersion, auxiliary->value);
                    auxiliary = pop(auxiliary);
                }
                auxiliary = pop(auxiliary);
                break;
            default:
                if (expression[i] != ' '){
                    draftVersion = push(draftVersion, expression[i]);
                    printf("Кладу в стек чисел %c\n", draftVersion->value);
                }
                break;
        }
    }
    show(auxiliary);
    return draftVersion;
}

int main(){

    char* expression = malloc(sizeof(char) * SIZE);
    if (expression == NULL){
        printf("ERROR: out of memory");
        return -1;
    }

    printf("Enter a mathematical expression in infix form\n");
    scanf("%[^\n]", expression);

    Element* result = fromInfixToPostfix(expression);
    printf("Postfix form is\n");
    show(result);

    free(expression);
    return 0;
}