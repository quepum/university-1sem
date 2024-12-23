#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *createNewList(int *errorCode) {
    List *list = calloc(1, sizeof(List));
    if (list == NULL) {
        *errorCode = -1;
        return NULL;
    }
    return list;
}

void addNewElement(List *list, int element, int *errorCode) {
    Node *newNode = calloc(1, sizeof(Node));
    if (newNode == NULL) {
        *errorCode = -1;
        return;
    }
    newNode->value = element;
    newNode->next = list->head;
    list->head = newNode;
}

void printContent(List *list) {
    Node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void deleteOddIndexes(List *list) {
    if (list == NULL || list->head == NULL || list->head->next == NULL) {
        return;
    }

    Node *current = list->head;
    Node *prev = NULL;
    int index = 0;
    while (current != NULL) {
        if (index % 2 != 0) {
            if (prev == NULL) {
                list->head = current->next;
                free(current);
                current = list->head;
            } else {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
        ++index;
    }
}

void deleteList(List *list) {
    if (list == NULL) return;
    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}