#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

bool testsForPush() {
    Element *testHead1 = NULL;
    testHead1 = push(testHead1, 5);
    if (testHead1->value != 5) {
        printf("Error with pushing 1st element\n");
        return false;
    }

    Element *testHead2 = NULL;
    testHead2 = push(testHead2, 5);
    testHead2 = push(testHead2, 0);
    testHead2 = push(testHead2, 3);
    if (testHead2->value != 3) {
        printf("Error with pushing element\n");
        return false;
    }
    removeStack(&testHead1);
    removeStack(&testHead2);
    return true;
}

bool testsForPopping() {
    Element *testHead1 = NULL;
    testHead1 = pop(testHead1);
    if (testHead1 != NULL) {
        printf("Error with popping empty stack\n");
        return false;
    }

    Element *testHead2 = NULL;
    testHead2 = push(testHead2, -5);
    testHead2 = push(testHead2, 3);
    testHead2 = push(testHead2, 9);
    testHead2 = pop(testHead2);
    if (testHead2->value != 3) {
        printf("Error with popping nonempty stack\n");
        return false;
    }
    removeStack(&testHead1);
    removeStack(&testHead2);
    return true;
}

bool testingForPeeking() {
    Element *testHead1 = NULL;
    if (peek(testHead1) != -1) {
        printf("Error with peeking empty stack\n");
        return false;
    }

    Element *testHead2 = NULL;
    testHead2 = push(testHead2, -20);
    testHead2 = push(testHead2, 100);
    testHead2 = push(testHead2, 0);
    testHead2 = pop(testHead2);
    if (peek(testHead2) != 100) {
        printf("Error with peeking nonempty stack\n");
        return false;
    }
    removeStack(&testHead1);
    removeStack(&testHead2);
    return true;
}

bool testingForSize() {
    Element *testHead1 = NULL;
    testHead1 = push(testHead1, -9);
    testHead1 = push(testHead1, 45678);
    testHead1 = push(testHead1, 1);
    if (sizeStack(testHead1) != 3) {
        printf("Error with counting size of nonempty stack\n");
        return false;
    }

    Element *testHead2 = NULL;
    if (sizeStack(testHead2) != 0) {
        printf("Error with counting size of empty stack\n");
        return false;
    }
    removeStack(&testHead1);
    removeStack(&testHead2);
    return true;

}

bool runAllTestsForStack() {
    return testsForPopping() && testsForPush() && testingForPeeking() && testingForSize();
}