#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "stack.h"

#define SIZE 101

bool calculator(Element **head, const char operand, int *errorCode) {
    int secondElement = peek(*head);
    pop(head);
    int firstElement = peek(*head);
    pop(head);

    switch (operand) {
        case '-': {
            int tempResult = firstElement - secondElement;
            *head = push(*head, tempResult, errorCode);
            if (*errorCode == -1) {
                return false;
            }
            break;
        }
        case '+': {
            int tempResult = firstElement + secondElement;
            *head = push(*head, tempResult, errorCode);
            if (*errorCode == -1) {
                return false;
            }
            break;
        }
        case '*': {
            int tempResult = firstElement * secondElement;
            *head = push(*head, tempResult, errorCode);
            if (*errorCode == -1) {
                return false;
            }
            break;
        }
        case '/': {
            if (secondElement == 0) {
                *errorCode = -1;
                return false;
            }
            int tempResult = firstElement / secondElement;
            *head = push(*head, tempResult, errorCode);
            if (*errorCode == -1) {
                return false;
            }
            break;
        }
        default:
            break;
    }
    return true;
}

int processingExpression(const char expression[], int *errorCode) {
    int size = (int) strlen(expression);
    Element *stack = NULL;
    for (int i = 0; i < size; ++i) {
        switch (expression[i]) {
            case '+':
            case '-':
            case '*':
            case '/': {
                bool correct = calculator(&stack, expression[i], errorCode);
                if (!correct) {
                    return -1;
                }
                break;
            }
            default:
                if (expression[i] != ' ') {
                    stack = push(stack, expression[i] - '0', errorCode);
                    if (*errorCode == -1) {
                        return -1;
                    }
                }
                break;
        }
    }
    if (sizeStack(stack) > 1 || isEmpty(stack)) {
        *errorCode = -1;
    }

    int result = peek(stack);
    removeStack(&stack);
    return result;
}

bool testsCalculator() {
    int errorCode = 0;

    char testExp1[] = "9 6 - 1 2 + *";
    int result1 = processingExpression(testExp1, &errorCode);
    if (result1 != 9 || errorCode == -1) {
        return false;
    }

    char testExp2[] = "1 1 +";
    int result2 = processingExpression(testExp2, &errorCode);
    if (result2 != 2 || errorCode == -1) {
        return false;
    }

    char testExp3[] = "2 2 *";
    int result3 = processingExpression(testExp3, &errorCode);
    if (result3 != 4 && errorCode == -1) {
        return false;
    }

    char testExp4[] = "3 5 -";
    int result4 = processingExpression(testExp4, &errorCode);
    if (result4 != -2 && errorCode == -1) {
        return false;
    }

    char testExp5[] = "9 3 /";
    int result5 = processingExpression(testExp5, &errorCode);
    if (result5 != 3 && errorCode == -1) {
        return false;
    }

    char testExp6[] = "9 0 /";
    processingExpression(testExp6, &errorCode);
    if (errorCode == 0) {
        return false;
    }

    return true;
}

int main(void) {
    if (!testsCalculator()) {
        printf("Tests failed, something went wrong");
        return -1;
    }
    printf("The tests were passed successfully\n");

    char *expression = malloc(sizeof(char) * SIZE);
    if (expression == NULL) {
        printf("ERROR: out of memory");
        return -1;
    }

    printf("Enter a mathematical expression in postfix form\n");
    scanf("%[^\n]", expression);

    int errorCode = 0;
    int result = processingExpression(expression, &errorCode);

    if (errorCode == -1) {
        printf("ERROR\n");
    } else {
        printf("The result is %d", result);
    }
    free(expression);
    return 0;
}