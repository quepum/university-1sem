#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct Node {
    int key;
    char *value;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

typedef struct Dictionary {
    Node *root;
} Dictionary;

Node *createNode(const int key, char *value) {
    Node *node = malloc(sizeof(Node));
    assert(node != NULL);
    node->key = key;
    node->value = value;
    node->leftChild = NULL;
    node->rightChild = NULL;
    return node;
}

Dictionary *createDictionary() {
    Dictionary *tree = malloc(sizeof(Dictionary));
    assert(tree != NULL);
    tree->root = NULL;
    return tree;
}




