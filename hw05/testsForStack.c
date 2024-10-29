#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

bool testsForPush(){
    Element* testHead1 = NULL;
    testHead1 = push(testHead1, '5');
    if (testHead1->value != '5'){
        printf("Error with pushing 1st element\n");
        return false;
    }

    Element* testHead2 = NULL;
    testHead2 = push(testHead1, 5);
    testHead2 = push(testHead1, '0');
    testHead2 = push(testHead1, 'a');
    if (testHead2->value != 'a'){
        printf("Error with pushing element\n");
        return false;
    }
    return true;
}

bool testsForPopping(){
    Element* testHead1 = NULL;
    testHead1 = pop(testHead1);
    if (testHead1 != NULL){
        printf("Error with popping empty stack\n");
        return false;
    }

    Element* testHead2 = NULL;
    testHead2 = push(testHead2, 5);
    testHead2 = push(testHead2, 'e');
    testHead2 = push(testHead2, 'a');
    testHead2 = pop(testHead2);
    if (testHead2->value != 'e'){
        printf("Error with popping nonempty stack\n");
        return false;
    }
    return true;
}

bool testingForPeeking(){
    Element* testHead1 = NULL;
    if (peek(testHead1) != '0'){
        printf("Error with peeking empty stack\n");
        return false;
    }

    Element* testHead2 = NULL;
    testHead2 = push(testHead2, '5');
    testHead2 = push(testHead2, 'e');
    testHead2 = push(testHead2, 'a');
    testHead2 = pop(testHead2);
    if (peek(testHead2) != 'e'){
        printf("Error with peeking nonempty stack\n");
        return false;
    }
    return true;
}