#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct Element {
    int value;
    struct Element *next;
} Element;

Element *push(Element *head, int value, int *errorCode) {
    Element *element = calloc(1, sizeof(Element));
    if (element == NULL) {
        *errorCode = -1;
        printf("Out of memory");
        return NULL;
    }
    element->value = value;
    element->next = head;
    return element;
}

int pop(Element **head) {
    if (*head == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    int element = (*head)->value;
    Element *newElement = (*head)->next;
    free(*head);
    (*head) = newElement;
    return element;
}

int peek(Element *head) {
    if (head == NULL) {
        return -1;
    }
    return head->value;
}

int sizeStack(Element *head) {
    Element *current = head;
    int size = 0;
    while (current != NULL) {
        ++size;
        current = current->next;
    }
    return size;
}

bool isEmpty(Element *head) {
    return head == NULL;
}

void removeStack(Element **head) {
    Element *current = *head;
    Element *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}
