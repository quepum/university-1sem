#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Element *push(Element *head, int value) {
    Element *element = malloc(sizeof(Element)); //выделяем память для нового объекта
    element->value = value; //кладём в значение нового объекта значение которое хотим добавить
    element->next = head; //переводим указатель следующего элемента на тот который был первым до
    return element; //возвращаем указатель на новый созданный объект
}

Element *pop(Element *head) {
    if (head == NULL) {
        return head;
    }
    Element *elementNext = head->next; // если head есть, то этот указатель равен адресу след объекта
    free(head);
    return elementNext;
}

int peek(Element *head) {
    if (head == NULL) {
        return -1;
    }
    return head->value; //возвращаем значение указателя head если стек не пустой
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
