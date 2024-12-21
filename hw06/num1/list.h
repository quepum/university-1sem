#pragma once

typedef struct Node Node;
typedef struct List List;
typedef Node *Position;

// function that create new list
List *createList(int *errorCode);

// inserting an element by position
void insert(List *list, int position, int value, int *errorCode);

// function that finds a suitable position for inserting a new element
void addNewItemToList(List *list, int value, int *errorCode);

// print the contents of the list
void printList(List *list);

// find the position of the element in the list
int findPositionElement(List *list, int value);

// function that deletes element from list by position
void deleteElement(List *list, int position);

// function that deletes list
void removeList(List *list);

