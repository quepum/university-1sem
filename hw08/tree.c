#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    const char *key;
    const char *value;
    struct Node *leftChild;
    struct Node *rightChild;
    int height;
} Node;

Node *createNewNode(const char *key, const char *value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = strdup(key);
    node->value = strdup(value);
    node->leftChild = NULL;
    node->rightChild = NULL;
    node->height = 1;
    return node;
}

void freeNode(Node *node) {
    if (node) {
        free((void *)node->key);
        free((void *)node->value);
        free(node);
    }
}

Node *getValue(Node *node, const char *key) {
    if (node == NULL) {
        return NULL;
    }
    if (strcmp(key, node->key) == 0) {
        return node;
    }
    if (strcmp(key, node->key) < 0) {
        return getValue(node->leftChild, key);
    }
    return getValue(node->rightChild, key);
}

bool isKeyInTree(Node *node, const char *key) {
    return getValue(node, key) != NULL;
}

void freeAVL(Node *node) {
    if (node == NULL) {
        return;
    }
    freeAVL(node->leftChild);
    freeAVL(node->rightChild);
    freeNode(node);
}