#pragma once

typedef struct ListNode {
    void *data;
    struct ListNode *next;
} ListNode;

typedef struct List {
    ListNode *head;
} List;

// function for creating new list
List *createNewList();

// function that deletes list
void removeList(List *list);

// function that adds new element to list
void addElement(List *list, void *data);
