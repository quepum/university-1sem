#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include "testsForStack.h"

Element *push(Element *head, char value) {
    Element *element = calloc(1, sizeof(Element)); //выделяем память для нового объекта
    assert(element != NULL);
    element->value = value; //кладём в значение нового объекта значение котрое хотим добавить
    element->next = head; //переводим указатель следующего элемента на тот который был первым до
    return element; //возвращаем указатель на новый созданный объект
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