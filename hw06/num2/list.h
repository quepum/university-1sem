#pragma once

typedef struct Node Node;
typedef struct List List;

List *createList();

List *makeCircle(int n);

int counting(List *list, int m);