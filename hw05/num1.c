#include <stdio.h>
#include "stack.h"
#include "testsForStack.h"

#define SIZE 101

bool checkSecondBracket(Element **head, char bracket) {
    return peek(*head) == bracket;
}

bool isBalanced(const char str[], int size) {
    Element *stack = NULL;
    for (int i = 0; i < size; ++i) {
        switch (str[i]) {
            case '(':
            case '{':
            case '[':
                push(&stack, str[i]);
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

bool tests() {
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
    if (!(testsForStack() && tests())) {
        printf("Tests failed, something went wrong");
        return -1;
    }
    printf("The tests were passed successfully\n");

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
