#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "list.h"

typedef struct Node {
    int position;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

List *createList(){
    List *list = calloc(1, sizeof(List));
    assert(list != NULL);
    list->head = NULL;
    return list;
}

Node *createNode(){
    Node *node = calloc(1, sizeof(Node));
    assert(node != NULL);
    return node;
}

List *makeCircle(const int n){
    List *list = createList();
    Node *head = NULL;
    for (int i = n; i > 0; --i) {
        Node *warrior = createNode();
        warrior->position = i;
        warrior->next = head;
        head = warrior;
    }
    Node *temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    list->head = head;
    return list;
}
