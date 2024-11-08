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

int counting(List *list, const int m){
    Node *killer = list->head;
    Node *corpse = list->head;
    int i = 0;
    while (killer->next->position != killer->position){
        int counter = 1;
        while (counter != m){
            corpse = corpse->next;
            ++counter;
        }
        while (killer->next->position != corpse->position){
            killer = killer->next;
        }
        killer->next = corpse->next;
        killer = corpse->next;
        corpse = corpse->next;
        ++i;
    }
    return killer->position;
}