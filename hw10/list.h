#pragma once

typedef struct ListNode ListNode;
typedef struct List List;

// Создание нового списка
List *createNewList(int *errorCode);

// Удаление списка и его элементов
void removeList(List *list);

// Добавление элемента в начало списка
void addElement(List *list, void *data, int *errorCode);

// Получение головы списка
ListNode *getHead(List *list);

// Получение следующего элемента
ListNode *getNextNode(ListNode *node);

// Получение данных из элемента
void *getData(ListNode *node);