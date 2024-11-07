#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "list.h"

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

List *createList(){
    List *list = malloc(sizeof(List));
    assert(list != NULL);
    list->head = NULL;
    return list;
}

void insert(List *list, int position, int value){
    Node *new = malloc(sizeof(Node));
    assert(new != NULL);
    new->value = value;
    new->next = NULL;
    if (position == 0){
        new->next = list->head;
        list->head = new;
        return;
    }
    Node *temp = list->head;
    for(int i = 0; i < position - 1; ++i){
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
}

void orderInsert(List *list, int value){
    Node *temp = list->head;
    if (temp == NULL){
        insert(list, 0, value);
        return;
    }
    int i = 0;
    while (temp->value < value){
        temp = temp->next;
        ++i;
        if (temp == NULL){
            insert(list, i, value);
            return;
        }
    }
    insert(list, i, value);
}

void deleteElement(List *list, int position){
    Node *temp = list->head;
    if (position == 0){
        list->head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    if (temp2 == NULL) {
        free(temp);
    }
    temp->next = temp2->next;
    free(temp2);
}

int findPositionElement(List* list, int value){
    Node *temp = list->head;
    int position = 0;
    while (temp->value != value){
        ++position;
        temp = temp->next;
        if (temp == NULL){
            return -1;
        }
    }
    return position;
}

void printList(List *list) {
    Node *temp = list->head;
    printf("[");
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("]\n");
}