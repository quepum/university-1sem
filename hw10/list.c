#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

void showList(List *list) {
    Node *temp = list->head;
    if (temp == NULL) {
        printf("The list is empty!\n");
        return;
    }
    printf("The list is: ");
    while (temp->next != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("%d ", temp->value);
    printf("\n");
}

void insert(List *list, const int value) {
    Node *temp1 = malloc(sizeof(Node));
    if (temp1 == NULL) {
        printf("Out of memory\n");
        exit(1);
    }
    temp1->value = value;
    temp1->next = NULL;
    if (list->head == NULL) {
        list->head = temp1;
    } else {
        temp1->next = list->head->next;
        list->head->next = temp1;
    }
}

List *createList() {
    List *list = malloc(sizeof(List));
    assert(list != NULL);
    return list;
}

int listLength(List *list) {
    Node *temp = list->head;
    int length = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }
    return length;
}

int accessElement(List *list, const int index) {
    Node *temp = list->head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Error: index out of range\n");
            exit(1);
        }
    }
    return temp->value;
}