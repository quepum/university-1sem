#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    int key;
    char *value;
    struct Node *leftChild;
    struct Node *rightChild;
} Dictionary;

Dictionary *createNewNode(int key, char *value, int *errorCode) {
    Dictionary *node = (Dictionary *) malloc(sizeof(Dictionary));
    if (node == NULL) {
        *errorCode = -1;
        return NULL;
    }
    node->key = key;
    node->value = strdup(value);
    node->leftChild = NULL;
    node->rightChild = NULL;
    return node;
}

void freeNode(Dictionary *node) {
    if (node == NULL) {
        return;
    }
    free(node->value);
    freeNode(node->leftChild);
    freeNode(node->rightChild);
    free(node);
}

Dictionary *insert(Dictionary *node, int key, char *value, int *errorCode) {
    if (node == NULL) {
        Dictionary *new = createNewNode(key, value, errorCode);
        if (*errorCode != 0) {
            return NULL;
        }
        return new;
    }
    if (*errorCode != 0) {
        return node;
    }

    if (key < node->key) {
        node->leftChild = insert(node->leftChild, key, value, errorCode);
        if (*errorCode != 0) {
            return node;
        }
    } else if (key > node->key) {
        node->rightChild = insert(node->rightChild, key, value, errorCode);
        if (*errorCode != 0) {
            return node;
        }
    } else {
        free(node->value);
        node->value = strdup(value);
        return node;
    }
    return node;
}

char *getValue(Dictionary *node, int key) {
    if (node == NULL) {
        return NULL;
    }
    if (key == node->key) {
        return node->value;
    }
    if (key < node->key) {
        return getValue(node->leftChild, key);
    }
    return getValue(node->rightChild, key);
}

bool isKeyInDictionary(Dictionary *node, int key) {
    return getValue(node, key) != NULL;
}

Dictionary *minValueNode(Dictionary *node) {
    Dictionary *current = node;
    while (current && current->leftChild != NULL)
        current = current->leftChild;
    return current;
}

Dictionary *deleteElement(Dictionary *node, int key) {
    if (node == NULL) {
        return node;
    }

    if (key < node->key) {
        node->leftChild = deleteElement(node->leftChild, key);
    } else if (key > node->key) {
        node->rightChild = deleteElement(node->rightChild, key);
    } else {
        if (node->leftChild == NULL || node->rightChild == NULL) {
            Dictionary *tmp = node->leftChild ? node->leftChild : node->rightChild;
            if (tmp == NULL) {
                freeNode(node);
                return NULL;
            } else {
                Dictionary *oldNode = node;
                node = tmp;
                freeNode(oldNode);
            }
        } else {
            Dictionary *temp = minValueNode(node->rightChild);
            free(node->value);
            char *valueCopy = strdup(temp->value);
            node->value = valueCopy;
            node->key = temp->key;
            node->rightChild = deleteElement(node->rightChild, temp->key);
            return node;
        }
    }
    return node;
}

void freeDictionary(Dictionary *node) {
    if (node != NULL) {
        freeDictionary(node->leftChild);
        freeDictionary(node->rightChild);
        freeNode(node);
    }
}