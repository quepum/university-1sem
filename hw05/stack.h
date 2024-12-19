#pragma once

#include <stdbool.h>

typedef struct Element {
    char value;
    struct Element *next;
} Element;

// function that adds a new element to the stack
Element *push(Element *head, char value);

// function that removes the first element of the stack
char pop(Element **head);

// function that returns the value of the first element in the stack
char peek(Element *head);

// function that outputs the current contents of the stack
void show(Element *head);

// function that reports if the stack is empty
bool isEmpty(Element *head);

