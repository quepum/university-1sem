#pragma once

typedef struct Node Node;
typedef struct List List;
typedef Node *Position;
List *createList();

//inserting an element by position
void insert(List *list, int position, int value);

//find a suitable position for inserting a new element
void orderInsert(List *list, int value);

//print the contents of the list
void printList(List *list);

//find the position of the element in the list
int findPositionElement(List* list, int value);

void deleteElement(List *list, int position);

