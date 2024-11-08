#pragma once
#include <stdbool.h>

typedef struct Node Node;
typedef struct List List;

List *createList();
Node *createNode();

//looping the list
List *makeCircle(int n);

//function that counts the positions of the killers and their victims
int counting(List *list, int m);

//some tests
bool tests();