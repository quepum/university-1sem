#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

char push(Element **head, char value) {
    Element *element = calloc(1, sizeof(Element)); //выделяем память для нового объекта
    if (element == NULL) {
        printf("Out of memory\n");
        return -1;
    }
    element->value = value; //кладём в значение нового объекта значение которое хотим добавить
    element->next = *head;//переводим указатель следующего элемента на тот который был первым до
    *head = element;
    return element->value; //возвращаем указатель на новый созданный объект
}

char pop(Element **head) {
    if (*head == NULL) {
        return 0;
    }
    char element = (*head)->value;
    Element *newElement = (*head)->next;
    free(*head);
    (*head) = newElement;
    return element;
}

char peek(Element *head) {
    if (head == NULL) {
        return '\0';
    }
    return head->value; //возвращаем значение указателя head если стек не пустой
}

void show(Element *head) {
    Element *current = head;
    while (current != NULL) {
        printf("%c\n", current->value);
        current = current->next;
    }
    printf("\n");
}

void freeStack(Element *head) {
    if (head == NULL)
        return;
    Element *element = head;
    Element *nextElement = NULL;
    while (element->next != NULL) {
        nextElement = element->next;
        free(element);
        element = nextElement;
    }
    free(nextElement);
}