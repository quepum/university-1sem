#pragma once

#include <stdbool.h>

typedef struct Node {
    const char *key;
    const char *value;
    struct Node *leftChild;
    struct Node *rightChild;
    int height;
} Node;

Node *insert(Node *node, const char *key, const char *value);
Node *getValue(Node *node, const char *key);
bool isKeyInTree(Node *node, const char *key);
Node *deleteNode(Node *root, const char *key);
void freeAVL(Node *node);