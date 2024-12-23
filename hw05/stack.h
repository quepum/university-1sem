#pragma once

typedef struct Element {
    char value;
    struct Element *next;
} Element;

// function that adds a new element to the stack
char push(Element **head, char value, int *errorCode);

// function that removes the first element of the stack
char pop(Element **head);

// function that returns the value of the first element in the stack
char peek(Element *head);

// function for deleting stack contents
void freeStack(Element *head);