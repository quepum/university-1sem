#pragma once

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

// function that creates new list
List *createNewList(int *errorCode);

// function that adds element to list
void addNewElement(List *list, int element, int *errorCode);

// function that show list contents
void printContent(List *result);

// function that deletes elements with odd indexes
void deleteOddIndexes(List *list);

// function that deletes list
void deleteList(List *list);
