#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char *key;
    char *value;
    struct Node *leftChild;
    struct Node *rightChild;
    int height;
} Dictionary;

Dictionary *createNewNode(const char *key, const char *value, int *errorCode) {
    Dictionary *node = (Dictionary *) malloc(sizeof(Dictionary));
    if (node == NULL) {
        *errorCode = -1;
        return NULL;
    }
    node->key = strdup(key);
    node->value = strdup(value);
    node->leftChild = NULL;
    node->rightChild = NULL;
    node->height = 1;
    return node;
}

void freeNode(Dictionary *node) {
    if (node) {
        free(node->key);
        free(node->value);
        free(node);
    }
}

int max(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

int updateHeight(Dictionary *node) {
    return (node == NULL) ? 0 : node->height;
}

Dictionary *rotateRight(Dictionary *node) {
    Dictionary *new = node->leftChild;
    Dictionary *tmp = new->rightChild;

    new->rightChild = node;
    node->leftChild = tmp;

    node->height = max(updateHeight(node->leftChild), updateHeight(node->rightChild)) + 1;
    new->height = max(updateHeight(new->leftChild), updateHeight(new->rightChild)) + 1;

    return new;
}

Dictionary *rotateLeft(Dictionary *node) {
    Dictionary *new = node->rightChild;
    Dictionary *tmp = new->leftChild;

    new->leftChild = node;
    node->rightChild = tmp;

    node->height = max(updateHeight(node->leftChild), updateHeight(node->rightChild)) + 1;
    new->height = max(updateHeight(new->leftChild), updateHeight(new->rightChild)) + 1;

    return new;
}

int getBalance(Dictionary *node) {
    return (node == NULL) ? 0 : updateHeight(node->leftChild) - updateHeight(node->rightChild);
}

Dictionary *insert(Dictionary *node, const char *key, const char *value, int *errorCode) {
    if (node == NULL) {
        Dictionary *new = createNewNode(key, value, errorCode);
        if (*errorCode != 0) {
            return NULL;
        }
        return new;
    }
    if (strcmp(key, node->key) < 0) {
        node->leftChild = insert(node->leftChild, key, value, errorCode);
    } else if (strcmp(key, node->key) > 0) {
        node->rightChild = insert(node->rightChild, key, value, errorCode);
    } else {
        free(node->value);
        node->value = strdup(value);
        return node;
    }

    node->height = 1 + max(updateHeight(node->leftChild), updateHeight(node->rightChild));
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

const char *getValue(Dictionary *node, const char *key) {
    if (node == NULL) {
        return NULL;
    }
    if (strcmp(key, node->key) == 0) {
        return node->value;
    }
    if (strcmp(key, node->key) < 0) {
        return getValue(node->leftChild, key);
    }
    return getValue(node->rightChild, key);
}

bool isKeyInTree(Dictionary *node, const char *key) {
    return getValue(node, key) != NULL;
}

Dictionary *minValueNode(Dictionary *node) {
    Dictionary *current = node;
    while (current->leftChild != NULL)
        current = current->leftChild;
    return current;
}

Dictionary *deleteNode(Dictionary *root, const char *key) {
    if (root == NULL) {
        return root;
    }
    if (strcmp(key, root->key) < 0) {
        root->leftChild = deleteNode(root->leftChild, key);

    } else if (strcmp(key, root->key) > 0) {
        root->rightChild = deleteNode(root->rightChild, key);
    } else {
        if ((root->leftChild == NULL) || (root->rightChild == NULL)) {
            Dictionary *temp = root->leftChild ? root->leftChild : root->rightChild;
            if (temp == NULL) {
                freeNode(root);
                return NULL;
            } else {
                Dictionary *oldRoot = root;
                root = temp;
                freeNode(oldRoot);
            }
        } else {
            Dictionary *temp = minValueNode(root->rightChild);
            free(root->key);
            char *keyCopy = strdup(temp->key);
            root->key = keyCopy;
            free(root->value);
            char *valueCopy = strdup(temp->value);
            root->value = valueCopy;
            root->rightChild = deleteNode(root->rightChild, temp->key);
        }
    }

    if (root == NULL) return root;

    root->height = 1 + max(updateHeight(root->leftChild), updateHeight(root->rightChild));
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

void freeTree(Dictionary *node) {
    if (node == NULL) {
        return;
    }
    freeTree(node->leftChild);
    freeTree(node->rightChild);
    freeNode(node);
}

bool isAVL(Dictionary *node) {
    if (node == NULL) {
        return true;
    }
    int balance = getBalance(node);
    if (balance < -1 || balance > 1) {
        return false;
    }
    if (node->leftChild != NULL && strcmp(node->key, node->leftChild->key) < 0) {
        return false;
    }
    if (node->rightChild != NULL && strcmp(node->key, node->rightChild->key) > 0) {
        return false;
    }
    return isAVL(node->leftChild) && isAVL(node->rightChild);
}