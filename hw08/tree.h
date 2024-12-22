#pragma once

#include <stdbool.h>

typedef struct Node {
    const char *key;
    const char *value;
    struct Node *leftChild;
    struct Node *rightChild;
    int height;
} Node;

// function that adds a value by a given key to a dictionary
Node *insert(Node *node, const char *key, const char *value);

// function that finds a value by a given key in a dictionary
Node *getValue(Node *node, const char *key);

// function that checks for the presence of a given key
bool isKeyInTree(Node *node, const char *key);

// function that removes a given key and its value from the dictionary
Node *deleteNode(Node *root, const char *key);

// function that deletes tree
void freeAVL(Node *node);