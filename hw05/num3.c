#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "stack.h"
#include "testsForStack.h"

#define SIZE 101


Element* fromInfixToPostfix(const char expression[]){
    Element* answer = NULL;

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

    return 0;
}