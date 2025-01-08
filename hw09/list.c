#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

typedef struct Node {
    char *word;
    int count;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

List *createList() {
    List *list = (List *) calloc(1, sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    return list;
}

void deleteList(List *list) {
    if (list == NULL) {
        return;
    }
    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp->word);
        free(temp);
    }
    free(list);
}

bool addNewElement(List *list, char *word) {
    if (list == NULL || word == NULL) {
        return false;
    }
    Node *newNode = (Node *) calloc(1, sizeof(Node));
    if (newNode == NULL) {
        return false;
    }

    newNode->word = strdup(word);
    if (newNode->word == NULL) {
        free(newNode);
        return false;
    }
    newNode->count = 1;
    newNode->next = list->head;
    list->head = newNode;
    return true;
}

Node *findElement(List *list, char *word) {
    if (list == NULL || word == NULL) {
        return NULL;
    }
    Node *current = list->head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void incrementCount(Node *node) {
    if (node != NULL) {
        node->count++;
    }
}

int getListLength(List *list) {
    if (list == NULL) {
        return 0;
    }
    int length = 0;
    Node *current = list->head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

void printList(List *list) {
    if (list == NULL) {
        return;
    }
    Node *current = list->head;
    while (current != NULL) {
        printf("Word: %s, Count: %d\n", current->word, current->count);
        current = current->next;
    }
}