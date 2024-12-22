#include "list.h"
#include <stdlib.h>
#include <stdio.h>

List *createNewList() {
    List *list = (List *) malloc(sizeof(List));
    if (list == NULL) {
        perror("Memory error");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    return list;
}

void removeList(List *list) {
    if (list == NULL) {
        return;
    }

    ListNode *current = list->head;
    while (current != NULL) {
        ListNode *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

void addElement(List *list, void *data, int *errorCode) {
    ListNode *newNode = (ListNode *) malloc(sizeof(ListNode));
    if (newNode == NULL) {
        *errorCode = -1;
        printf("Memory error");
        return;
    }
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}
