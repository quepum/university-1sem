#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "tree.h"

typedef struct Node {
    int key;
    char *value;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

struct Dictionary {
    Node *root;
};

Node *createNode(const int key, char *value) {
    Node *newNode = calloc(1, sizeof(Node));
    assert(newNode != NULL && "Memory error\n");
    newNode->key = key;
    newNode->value = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

Dictionary *createDictionary() {
    Dictionary *dictionary = calloc(1, sizeof(Dictionary));
    assert(dictionary != NULL && "Memory error\n");
    dictionary->root = NULL;
    return dictionary;
}

Node *insertRecursion(Node **root, const int key, char *value) {
    if (*root == NULL) {
        *root = createNode(key, value);
    } else if (key <= (*root)->key) {
        (*root)->leftChild = insertRecursion(&(*root)->leftChild, key, value);
    } else {
        (*root)->rightChild = insertRecursion(&(*root)->rightChild, key, value);
    }
    return *root;
}

void insert(Dictionary *dictionary, const int key, char *value) {
    insertRecursion(&(dictionary->root), key, value);
}

bool search(Node *root, const int key) {
    if (root == NULL) {
        return false;
    } else if (root->key == key) {
        return true;
    } else if (key <= root->key) {
        return search(root->leftChild, key);
    } else {
        return search(root->rightChild, key);
    }
}

char *getValueRecursion(Node *root, const int key) {
    if (root == NULL) {
        return "NULL";
    } else if (root->key == key) {
        return root->value;
    } else if (key <= root->key) {
        return getValueRecursion(root->leftChild, key);
    } else {
        return getValueRecursion(root->rightChild, key);
    }
}

char *getValue(Dictionary *dictionary, const int key) {
    return getValueRecursion(dictionary->root, key);
}

bool isKeyInTheDictionary(Dictionary *dictionary, const int key) {
    if (search(dictionary->root, key)) {
        return true;
    }
    return false;
}

Node *minValueNode(Node *node) {
    Node *current = node;

    while (current && current->leftChild != NULL)
        current = current->leftChild;

    return current;
}

Node *deleteRecursion(Node *root, const int key) {
    if (root == NULL) {
        return NULL;
    } else if (key < root->key) {
        root->leftChild = deleteRecursion(root->leftChild, key);
    } else if (key > root->key) {
        root->rightChild = deleteRecursion(root->rightChild, key);
    } else {
        if (root->leftChild == NULL && root->rightChild == NULL) {
            free(root);
            root = NULL;
        } else if (root->leftChild == NULL) {
            Node *temp = root;
            root = root->rightChild;
            free(temp);
        } else if (root->rightChild == NULL) {
            Node *temp = root;
            root = root->leftChild;
            free(temp);
        } else {
            Node *temp = minValueNode(root->rightChild);
            root->key = temp->key;
            root->rightChild = deleteRecursion(root->rightChild, key);
        }
        return root;
    }
}

void removeKey(Dictionary *dictionary, const int key) {
    deleteRecursion(dictionary->root, key);
}

void finalDeletion(Node *root) {
    if (root == NULL) {
        return;
    }
    finalDeletion(root->leftChild);
    finalDeletion(root->rightChild);
    free(root);
}

void deleteDictionary(Dictionary *dictionary) {
    finalDeletion(dictionary->root);
}

Node *findNodeByKey(Node *root, const int key) {
    if (root->key == key) {
        return root;
    } else if (key > root->key) {
        return findNodeByKey(root->rightChild, key);
    } else {
        return findNodeByKey(root->leftChild, key);
    }
}

void changeData(Dictionary *dictionary, const int key, char *newData) {
    Node *temp = findNodeByKey(dictionary->root, key);
    temp->value = newData;
}
