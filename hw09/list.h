#pragma once

typedef struct Node {
    char *word;
    int frequency;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

List *create_list();
void insert(List *list, char *word);
void freeList(List *list);
