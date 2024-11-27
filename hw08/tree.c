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

int max(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

int heightUpdater(Node *node) {
    return (node == NULL) ? 0 : node->height;
}

Node *rotateRight(Node *node) {
    Node *new = node->leftChild;
    Node *tmp = new->rightChild;

    new->rightChild = node;
    node->leftChild = tmp;

    node->height = max(heightUpdater(node->leftChild), heightUpdater(node->rightChild)) + 1;
    new->height = max(heightUpdater(new->leftChild), heightUpdater(new->rightChild)) + 1;

    return new;
}

Node *rotateLeft(Node *node) {
    Node *new = node->rightChild;
    Node *tmp = new->leftChild;

    new->leftChild = node;
    node->rightChild = tmp;

    node->height = max(heightUpdater(node->leftChild), heightUpdater(node->rightChild)) + 1;
    new->height = max(heightUpdater(new->leftChild), heightUpdater(new->rightChild)) + 1;

    return new;
}

int getBalance(Node *node) {
    return (node == NULL) ? 0 : heightUpdater(node->leftChild) - heightUpdater(node->rightChild);
}

Node *insert(Node *node, const char *key, const char *value) {
    if (node == NULL) {
        return createNewNode(key, value);
    }
    if (strcmp(key, node->key) < 0) {
        node->leftChild = insert(node->leftChild, key, value);
    } else if (strcmp(key, node->key) > 0) {
        node->rightChild = insert(node->rightChild, key, value);
    } else {
        free((void *) node->value);
        node->value = strdup(value);
        return node;
    }

    node->height = 1 + max(heightUpdater(node->leftChild), heightUpdater(node->rightChild));
    int balance = getBalance(node);

    if (balance > 1 && strcmp(key, node->leftChild->key) < 0) {
        return rotateRight(node);
    }
    if (balance < -1 && strcmp(key, node->rightChild->key) > 0) {
        return rotateLeft(node);
    }
    if (balance > 1 && strcmp(key, node->leftChild->key) > 0) {
        node->leftChild = rotateLeft(node->leftChild);
        return rotateRight(node);
    }
    if (balance < -1 && strcmp(key, node->rightChild->key) < 0) {
        node->rightChild = rotateRight(node->rightChild);
        return rotateLeft(node);
    }

    return node;
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

Node *minValueNode(Node *node) {
    Node *current = node;
    while (current->leftChild != NULL)
        current = current->leftChild;
    return current;
}

Node *deleteNode(Node *root, const char *key) {
    if (root == NULL) {
        return root;
    }
    if (strcmp(key, root->key) < 0) {
        root->leftChild = deleteNode(root->leftChild, key);

    } else if (strcmp(key, root->key) > 0) {
        root->rightChild = deleteNode(root->rightChild, key);
    } else {
        if ((root->leftChild == NULL) || (root->rightChild == NULL)) {
            Node *temp = root->leftChild ? root->leftChild : root->rightChild;
            if (temp == NULL) {
                freeNode(root);
                return NULL;
            } else {
                Node *oldRoot = root;
                root = temp;
                freeNode(oldRoot);
            }
        } else {
            Node *temp = minValueNode(root->rightChild);
            root->key = temp->key;
            root->value = temp->value;
            root->rightChild = deleteNode(root->rightChild, temp->key);
        }
    }

    if (root == NULL) return root;

    root->height = 1 + max(heightUpdater(root->leftChild), heightUpdater(root->rightChild));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->leftChild) >= 0) {
        return rotateRight(root);
    }
    if (balance > 1 && getBalance(root->leftChild) < 0) {
        root->leftChild = rotateLeft(root->leftChild);
        return rotateRight(root);
    }
    if (balance < -1 && getBalance(root->rightChild) <= 0) {
        return rotateLeft(root);
    }
    if (balance < -1 && getBalance(root->rightChild) > 0) {
        root->rightChild = rotateRight(root->rightChild);
        return rotateLeft(root);
    }

    return root;
}

void freeAVL(Node *node) {
    if (node == NULL) {
        return;
    }
    freeAVL(node->leftChild);
    freeAVL(node->rightChild);
    freeNode(node);
}