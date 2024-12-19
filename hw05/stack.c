#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

Element *push(Element *head, char value) {
    Element *element = malloc(sizeof(Element)); //выделяем память для нового объекта
    assert(element != NULL);
    element->value = value; //кладём в значение нового объекта значение котрое хотим добавить
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

char peek(Element *head) {
    if (head == NULL) {
        return '0';
    }
    return head->value; //возвращаем значение указателя head если стек не пустой
}

void show(Element *head) {
    Element *current = head;
    while (current != NULL) {
        printf("%c ", current->value);
        current = current->next;
    }
    printf("\n");
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
