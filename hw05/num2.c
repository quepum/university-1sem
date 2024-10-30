#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "stack.h"
#include "testsForStack.h"
#define SIZE 101

bool calculator(Element** head, const char operand, int* errorCode) {
    int secondElement = peek(*head);
    *head = pop(*head);
    int firstElement = peek(*head);
    *head = pop(*head);


    switch (operand) {
        case '-': {
            int tempResult = firstElement - secondElement;
            *head = push(*head, tempResult);
            break;
        }
        case '+': {
            int tempResult = firstElement + secondElement;
            *head = push(*head, tempResult);
            break;
        }
        case '*': {
            int tempResult = firstElement * secondElement;
            *head = push(*head, tempResult);
            break;
        }
        case '/': {
            if (secondElement == 0){
                *errorCode = -1;
                return false;
            }
            int tempResult = firstElement / secondElement;
            *head = push(*head, tempResult);
            break;
        }
        default:
            break;
    }
    return true;
}

int processingExpression(const char expression[], int* errorCode){
    int size = (int)strlen(expression);
    Element* stack = NULL;
    for (int i = 0; i < size; ++i){
        switch (expression[i]) {
            case '+':
            case '-':
            case '*':
            case '/': {
                bool correct = calculator(&stack, expression[i], errorCode);
                if (!correct){
                    return false;
                }
                break;
            }
            default:
                if (expression[i] != ' ') {
                    stack = push(stack, (int)strtol(&expression[i], NULL, 10));
                }
                break;
        }
    }
    if (sizeStack(stack) != 1){
        *errorCode = -1;
    }
    return peek(stack);
}


bool testsCalculator(){
    int errorCode = 0;

    char testExp1[] = "9 6 - 1 2 + *";
    int result1 = processingExpression(testExp1, &errorCode);
    if (result1 != 9 || errorCode == -1){
        return false;
    }

    char testExp2[] = "1 1 +";
    int result2 = processingExpression(testExp2, &errorCode);
    if (result2 != 2 || errorCode == -1){
        return false;
    }

    char testExp3[] = "2 2 *";
    int result3 = processingExpression(testExp3, &errorCode);
    if (result3 != 4 && errorCode == -1){
        return false;
    }

    char testExp4[] = "3 5 -";
    int result4 = processingExpression(testExp4, &errorCode);
    if (result4 != -2 && errorCode == -1){
        return false;
    }

    char testExp5[] = "9 3 /";
    int result5 = processingExpression(testExp5, &errorCode);
    if (result5 != 3 && errorCode == -1){
        return false;
    }

    char testExp6[] = "9 0 /";
    processingExpression(testExp6, &errorCode);
    if (errorCode == 0){
        return false;
    }

    return true;
}

int main(void){
    if(!(testsForPopping() && testsForPush() && testingForPeeking() && testingForSize() && testsCalculator())){
        printf("Tests failed, something went wrong");
        return -1;
    } else {
        printf("%s", "The tests were passed successfully\n");
    }

    char* expression = malloc(sizeof(char) * SIZE);
    if (expression == NULL){

        printf("ERROR: out of memory");
        return -1;
    }

    printf("Enter a mathematical expression in postfix form\n");
    scanf("%[^\n]", expression);

    int errorCode = 0;
    int result = processingExpression(expression, &errorCode);

    (errorCode == -1) ? printf("ERROR\n") : printf("The result is %d", result);
    return 0;
}