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

char *getValue(const Node *root, const int key) {
    if (root == NULL) {
        return "NULL";
    }
    if (root->key == key) {
        return root->value;
    }
    if (key <= root->key) {
        return getValue(root->leftChild, key);
    }
    return getValue(root->rightChild, key);
}

char *findValueByKey(Dictionary *dictionary, const int key) {
    return getValue(dictionary->root, key);
}

bool keySearcher(Node *root, const int key) {
    if (root == NULL) {
        return false;
    }
    if (root->key == key) {
        return true;
    }
    if (key <= root->key) {
        return getValue(root->leftChild, key);
    }
    return getValue(root->rightChild, key);
}

bool checkTheExistenceOfTheKey(Dictionary *dictionary, const int key) {
    return keySearcher(dictionary->root, key);
}

void changeValue(Node *root, char *value) {
    root->value = value;
}

Node *insertRecursion(Node **root, const int key, char *value, bool existenceOfKey) {
    if (*root == NULL) {
        if (existenceOfKey) {
            changeValue(*root, value);
        } else {
            *root = createNode(key, value);
        }
    } else if (key <= (*root)->key) {
        (*root)->rightChild = insertRecursion(&(*root)->rightChild, key, value, existenceOfKey);
    } else {
        (*root)->leftChild = insertRecursion(&(*root)->leftChild, key, value, existenceOfKey);
    }
    return *root;
}

void insert(Dictionary *dictionary, const int key, char *value) {
    insertRecursion(&dictionary->root, key, value, checkTheExistenceOfTheKey(dictionary, key));
}





