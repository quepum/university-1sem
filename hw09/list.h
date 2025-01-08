#pragma once
#include <stdbool.h>

typedef struct Node Node;
typedef struct List List;

// function that create new list
List *createList();

// function that deletes list
void deleteList(List *list);

// function that adds a new word to the list
bool addNewElement(List *list, char *word);

// function that finds a word in the list
Node *findElement(List *list, char *word);

// function that increments the count of a node
void incrementCount(Node *node);

// function that gets list length
int getListLength(List *list);

// function that shows all list elements
void printList(List *list);
