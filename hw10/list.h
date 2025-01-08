#pragma once

typedef struct ListNode ListNode;
typedef struct List List;

// function for creating new list
List *createNewList(int *errorCode);

// function that deletes list
void removeList(List *list);

// function that adds new element to list
void addElement(List *list, void *data, int *errorCode);

// function that returns head of the list
ListNode *getHead(List *list);

// function that returns next node of the list
ListNode *getNextNode(ListNode *node);

// function that gets data from list node
void *getData(ListNode *node);