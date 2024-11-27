#pragma once

#include <stdbool.h>

typedef struct Node {
    const char *key;
    const char *value;
    struct Node *leftChild;
    struct Node *rightChild;
    int height;
} Node;

Node *getValue(Node *node, const char *key);
bool isKeyInTree(Node *node, const char *key);
void freeAVL(Node *node);