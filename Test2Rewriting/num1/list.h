#pragma once

#include <stdio.h>

// list structure
typedef struct List List;

// function that create list
List *createNewList(int *errorCode);

// function that deletes list
void removeList(List *list);

// function that writes element to file
void rewriteToFile(FILE *file, List *list);

// function that add new elements to file
bool addNewElement(List *linkedList, int element);