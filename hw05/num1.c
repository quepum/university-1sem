#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

#define SIZE 101

bool checkSecondBracket(Element **head, char bracket) {
    return peek(*head) == bracket;
}

bool isBalanced(const char str[], int size) {
    int errorCode = 0;
    Element *stack = NULL;
    for (int i = 0; i < size; ++i) {
        switch (str[i]) {
            case '(':
            case '{':
            case '[':
                push(&stack, str[i], &errorCode);
                if (errorCode == -1) {
                    return false;
                }
                break;
            case ')':
                if (!checkSecondBracket(&stack, '(')) {
                    return false;
                }
                pop(&stack);
                break;
            case '}':
                if (!checkSecondBracket(&stack, '{')) {
                    return false;
                }
                pop(&stack);
                break;
            case ']':
                if (!checkSecondBracket(&stack, '[')) {
                    return false;
                }
                pop(&stack);
                break;
        }
    }
    char res = peek(stack);
    freeStack(stack);
    return res == '\0';
}

bool runAllTests() {
    char testingString1[6] = "({[]})";
    if (!isBalanced(testingString1, 6)) {
        return false;
    }

    char testingString2[6] = "([{]})";
    if (isBalanced(testingString2, 6)) {
        return false;
    }

    char testingString3[10] = "[[][][]]]";
    if (isBalanced(testingString3, 10)) {
        return false;
    }

    char testingString4[10] = "[[][]]]]";
    if (isBalanced(testingString4, 10)) {
        return false;
    }
    return true;
}

int main(void) {
    if (!runAllTests()) {
        printf("Tests failed, something went wrong");
        return -1;
    }
    printf("The runAllTests were passed successfully\n");

    char string[SIZE] = {'\0'};
    printf("Enter a string no longer than 100 characters\n");
    scanf("%s", string);

    if (!isBalanced(string, SIZE)) {
        printf("INCORRECT\n");
    } else {
        printf("CORRECT");
    }
    return 0;
}
