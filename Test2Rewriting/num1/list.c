#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

List *createNewList(int *errorCode) {
    List *newList = calloc(1, sizeof(List));
    if (newList == NULL) {
        *errorCode = -1;
        return NULL;
    }
    return newList;
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

void rewriteToFile(FILE *file, List *list) {
    Node *tmp = list->head;
    if (tmp == NULL) {
        return;
    }
    while (tmp->next != NULL) {
        fprintf(file, "%d\n", tmp->value);
        tmp = tmp->next;
    }
    fprintf(file, "%d\n", tmp->value);
}

bool addNewElement(List *linkedList, int element) {
    Node *node = calloc(1, sizeof(Node));
    if (node == NULL) {
        return false;
    }
    node->value = element;
    node->next = NULL;

    if (linkedList->head == NULL) {
        linkedList->head = node;
    } else {
        Node *lastNode = linkedList->head;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = node;
    }
    return true;
}

