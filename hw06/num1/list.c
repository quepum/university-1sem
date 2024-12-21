#include <stdio.h>
#include <malloc.h>
#include "list.h"

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

List *createList(int *errorCode) {
    List *list = calloc(1, sizeof(List));
    if (list == NULL) {
        *errorCode = -1;
        return NULL;
    }
    return list;
}

void insert(List *list, int position, int value, int *errorCode) {
    Node *new = calloc(1, sizeof(Node));
    if (new == NULL) {
        *errorCode = -1;
        return;
    }
    new->value = value;
    new->next = NULL;
    if (position == 0) {
        new->next = list->head;
        list->head = new;
        return;
    }
    Node *temp = list->head;
    for (int i = 0; i < position - 1; ++i) {
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
}

void addNewItemToList(List *list, int value, int *errorCode) {
    Node *temp = list->head;
    if (temp == NULL) {
        insert(list, 0, value, errorCode);
        return;
    }
    int i = 0;
    while (temp->value < value) {
        temp = temp->next;
        ++i;
        if (temp == NULL) {
            insert(list, i, value, errorCode);
            return;
        }
    }
    insert(list, i, value, errorCode);
}

void deleteElement(List *list, int position) {
    Node *temp = list->head;
    if (position == 0) {
        list->head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    if (temp == NULL || temp->next == NULL) {
        return;
    }
    temp->next = temp2->next;
    free(temp2);
}

int findPositionElement(List *list, int value) {
    Node *temp = list->head;
    int position = 0;
    if (temp == NULL) {
        return -1;
    }
    while (temp->value != value) {
        ++position;
        temp = temp->next;
        if (temp == NULL) {
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

void removeList(List *list) {
    Node *tmp1 = list->head;
    Node *tmp2 = NULL;
    while (tmp1 != NULL) {
        tmp2 = tmp1->next;
        free(tmp1);
        tmp1 = tmp2;
    }
}