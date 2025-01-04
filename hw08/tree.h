#pragma once

#include <stdbool.h>

typedef struct Node Dictionary;

// function that adds a value by a given key to a dictionary
Dictionary *insert(Dictionary *node, const char *key, const char *value, int *errorCode);

// function that finds a value by a given key in a dictionary
const char *getValue(Dictionary *node, const char *key);

// function that checks for the presence of a given key
bool isKeyInTree(Dictionary *node, const char *key);

// function that removes a given key and its value from the dictionary
Dictionary *deleteNode(Dictionary *root, const char *key);

// function that deletes tree
void freeTree(Dictionary *node);

// function that checks the properties of the AVL-tree
bool isAVL(Dictionary *node);