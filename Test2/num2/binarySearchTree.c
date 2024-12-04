#include <malloc.h>
#include <assert.h>
#include "binarySearchTree.h"

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct BinarySearchTree {
    Node *root;
} BinarySearchTree;

Node *getNewNode(int value) {
    Node *newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insertRecursive(Node **root, int value) {
    if (*root == NULL) {
        *root = getNewNode(value);
    } else if (value <= (*root)->value) {
        (*root)->left = insertRecursive(&(*root)->left, value);
    } else {
        (*root)->right = insertRecursive(&(*root)->right, value);
    }
    return *root;
}

void insert(BinarySearchTree *dictionary, int value) {
    insertRecursive(&(dictionary->root), value);
}

BinarySearchTree *createTree() {
    BinarySearchTree *tree = malloc(sizeof(BinarySearchTree));
    assert(tree != NULL);
    tree->root = NULL;
    return tree;
}

void deleteRecursive(Node *root) {
    if (root == NULL) {
        return;
    }
    deleteRecursive(root->left);
    deleteRecursive(root->right);
    free(root);
}

void deleteTree(BinarySearchTree *dictionary) {
    deleteRecursive(dictionary->root);
}

void inOrderTraversal(Node *root, int array[], int *index) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left, array, index);
    array[*index] = root->value;
    ++(*index);
    inOrderTraversal(root->right, array, index);

}

void inOrderSort(int array[], int length) {
    BinarySearchTree *tree = createTree();
    for (int i = 0; i < length; i++) {
        insert(tree, array[i]);
    }
    int index = 0;
    inOrderTraversal(tree->root, array, &index);
    deleteTree(tree);
}

