#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "list.h"

List *createList() {
    List *list = malloc(sizeof(List));
    assert(list != NULL);
    list->head = NULL;
    return list;
}

void printList(List *list) {
    Node *temp = list->head;
    printf("[");
    while (temp != NULL) {
        printf("%s ", temp->word);
        temp = temp->next;
    }
    printf("]\n");
}

void insert(List *list, char *word) {
    Node *new = malloc(sizeof(Node));
    assert(new != NULL);
    new->word = word;
    new->frequency = 1;
    new->next = NULL;
    if (list->head != NULL) {
        new->next = list->head;
        list->head = new;
    } else {
        list->head = new;
    }
}

int getFrequency(List *list) {
    return list->head->frequency;
}

bool isEmpty(List *list) {
    return list == NULL;
}

char *getWord(List *list) {
    return list->head->word;
}

bool isInTheList(List *list, char *word) {
    Node *temp = list->head;
    while (temp != NULL) {
        if (strcmp(word, temp->word) == 0) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void freeList(List *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp->word);
        free(temp);
    }
    free(list);
}

void updateFrequency(List *list, char *word) {
    Node *temp = list->head;
    while (temp != NULL) {
        if (strcmp(word, temp->word) == 0) {
            ++temp->frequency;
            return;
        }
    }

}

void conveyFrequency(List* list, char* word, int newFrequency) {
    Node* temp = list->head;
    while (temp != NULL) {
        if (strcmp(word, temp->word) == 0) {
            temp->frequency = newFrequency;
            return;
        }
    }
}

int listLength(LinkedList* linkedList) {
    if (linkedList == NULL) {
        return 0;
    }
    Node* temp = linkedList->head;
    int length = 1;
    while(temp->next != NULL) {
        temp = temp->next;
        length++;
    }
    return length;
}