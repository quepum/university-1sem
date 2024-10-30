#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "testsForStack.h"

Element* push(Element* head, int value){
    Element* element = malloc(sizeof(Element)); //выделяем память для нового объекта
    element->value = value; //кладём в значение нового объекта значение котрое хотим добавить
    element->next = head; //переводим указатель следующего элемента на тот который был первым до
    return element; //возвращаем указатель на новый созданный объект
}

Element* pop(Element* head){
    if (head == NULL){
        return head;
    }
    Element* elementNext = head->next; // если head есть, то этот указатель равен адресу след объекта
    free(head);
    return elementNext;

}

int peek(Element* head){
    if (head == NULL){
        return -1;
    }
    return head->value; //возвращаем значение указателя head если стек не пустой
}

void show(Element* head){
    Element* current = head;
    while (current != NULL){
        printf("%d\n", current->value);
        current = current->next;
    }
    printf("\n");
}

int sizeStack(Element * head) {
    Element * current = head;
    int size = 0;
    while (current != NULL) {
        ++size;
        current = current->next;
    }
    return size;
}
