#include <stdlib.h>

typedef struct ListNode {
    void *data;
    struct ListNode *next;
} ListNode;

typedef struct List {
    struct ListNode *head;
} List;

List *createNewList(int *errorCode) {
    List *newList = (List *) calloc(1, sizeof(List));
    if (newList == NULL) {
        *errorCode = -1;
        return NULL;
    }
    return newList;
}

void removeList(List *list) {
    if (list == NULL) {
        return;
    }
    ListNode *current = list->head;
    while (current != NULL) {
        ListNode *next = current->next;
        if (current->data != NULL) {
            free(current->data);
        }
        free(current);
        current = next;
    }
    free(list);
}

void addElement(List *list, void *data, int *errorCode) {
    if (list == NULL) {
        *errorCode = 1;
        return;
    }
    ListNode *newNode = (ListNode *) malloc(sizeof(ListNode));
    if (newNode == NULL) {
        *errorCode = 2;
        return;
    }
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    *errorCode = 0;
}

ListNode *getHead(List *list) {
    if (list == NULL) {
        return NULL;
    }
    return list->head;
}

ListNode *getNextNode(ListNode *node) {
    if (node == NULL) {
        return NULL;
    }
    return node->next;
}

void *getData(ListNode *node) {
    if (node == NULL) {
        return NULL;
    }
    return node->data;
}