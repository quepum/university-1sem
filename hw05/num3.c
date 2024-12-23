#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "stack.h"

const int length = 101;

int rangOfOperand(const char operand) {
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

Element *fromInfixToPostfix(const char expression[], int *errorCode) {
    Element *draftVersion = NULL;
    Element *auxiliary = NULL;
    int size = (int) strlen(expression);

    for (int i = 0; i < size; ++i) {
        if (expression[i] != ' ' || expression[i] != '\n') {
            switch (expression[i]) {
                case '+':
                case '-':
                case '*':
                case '/': {
                    int rangCurrentOperand = rangOfOperand(expression[i]);
                    while (rangOfOperand(peek(auxiliary)) > rangCurrentOperand) {
                        draftVersion = push(draftVersion, peek(auxiliary), errorCode);
                        if (*errorCode == -1) {
                            deleteStack(&draftVersion);
                            deleteStack(&auxiliary);
                            return NULL;
                        }
                        pop(&auxiliary);
                    }
                    auxiliary = push(auxiliary, expression[i], errorCode);
                    if (*errorCode == -1) {
                        deleteStack(&draftVersion);
                        deleteStack(&auxiliary);
                        return NULL;
                    }
                    break;
                }
                case '(':
                    auxiliary = push(auxiliary, expression[i], errorCode);
                    if (*errorCode == -1) {
                        deleteStack(&draftVersion);
                        deleteStack(&auxiliary);
                        return NULL;
                    }
                    break;
                case ')':
                    while (peek(auxiliary) != '(') {
                        draftVersion = push(draftVersion, peek(auxiliary), errorCode);
                        if (*errorCode == -1) {
                            deleteStack(&draftVersion);
                            deleteStack(&auxiliary);
                            return NULL;
                        }
                        pop(&auxiliary);
                    }
                    pop(&auxiliary);
                    break;
                default:
                    if (expression[i] != ' ') {
                        draftVersion = push(draftVersion, expression[i], errorCode);
                        if (*errorCode == -1) {
                            deleteStack(&draftVersion);
                            deleteStack(&auxiliary);
                            return NULL;
                        }
                    }
                    break;
            }
        }
    }
    while (!isEmpty(auxiliary)) {
        draftVersion = push(draftVersion, peek(auxiliary), errorCode);
        if (*errorCode == -1) {
            deleteStack(&draftVersion);
            deleteStack(&auxiliary);
            return NULL;
        }
        pop(&auxiliary);
    }

    Element *answer = NULL;
    while (!isEmpty(draftVersion)) {
        answer = push(answer, peek(draftVersion), errorCode);
        if (*errorCode == -1) {
            deleteStack(&draftVersion);
            deleteStack(&auxiliary);
            return NULL;
        }
        pop(&draftVersion);
    }
    deleteStack(&auxiliary);
    deleteStack(&draftVersion);
    return answer;
}

bool checkAnswer(const char *test, const char *correctAnswer, int *errorCode) {
    Element *result = fromInfixToPostfix(test, errorCode);
    if (*errorCode == -1) {
        deleteStack(&result);
        return false;
    }
    int i = 0;
    while (result != NULL) {
        if (result->value != correctAnswer[i]) {
            return false;
        }
        result = result->next;
        ++i;
    }
    return true;
}

bool test() {
    int errorCode = 0;

    char *test1 = "(1 + 1) * 2 - (9 / 3)";
    char *correctAnswer1 = "11+2*93/-";
    if (!checkAnswer(test1, correctAnswer1, &errorCode)) {
        return false;
    }

    char *test2 = "2 + 3 * 4";
    char *correctAnswer2 = "234*+";
    if (!checkAnswer(test2, correctAnswer2, &errorCode)) {
        return false;
    }

    char *test3 = "(( 2 + 3 ) * 4 - 5 ) / 6";
    char *correctAnswer3 = "23+4*5-6/";
    if (!checkAnswer(test3, correctAnswer3, &errorCode)) {
        return false;
    }
    return true;
}

int main() {
    if (!test()) {
        printf("Tests failed, something went wrong");
        return -1;
    }
    printf("Tests were passed successfully\n");

    char *expression = malloc(sizeof(char) * length);
    if (expression == NULL) {
        printf("ERROR: out of memory");
        return -1;
    }

    printf("Enter a mathematical expression in infix form (no longer than 100 symbols)\n");
    scanf("%[^\n]", expression);

    int errorCode = 0;

    Element *result = fromInfixToPostfix(expression, &errorCode);
    if (errorCode == -1) {
        printf("Out of memory");
        free(expression);
        return -1;
    }
    printf("Postfix form is\n");
    show(result);

    free(expression);
    return 0;
}