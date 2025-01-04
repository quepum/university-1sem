#include <stdbool.h>
#pragma once

typedef struct Node Dictionary;

// function that inserts a new node by given key and value into the dictionary
Dictionary *insert(Dictionary *node, int key, char *value, int *errorCode);

// function that gets value from the dictionary by given key
char *getValue(Dictionary *node, int key);

// function that checks if given key exists in the dictionary
bool isKeyInDictionary(Dictionary *node, int key);

// function that deletes the key and its value from the dictionary
Dictionary *deleteElement(Dictionary *node, int key, int *errorCode);

// function that deletes dictionary
void freeDictionary(Dictionary *node);
