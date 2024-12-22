#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

typedef struct Node {
    int value;
    char operation;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

typedef struct Tree {
    Node *root;
} Tree;

Tree *createTree(int *errorCode) {
    Tree *tree = calloc(1, sizeof(Tree));
    if (tree == NULL) {
        *errorCode = 1;
        return NULL;
    }
    return tree;
}

bool nextIsDigit(const char expression[], int position) {
    return (expression[position + 1] != ' ' && expression[position + 1] != '+' && expression[position + 1] != '*' &&
            expression[position + 1] != '/' && expression[position + 1] != '(' && expression[position + 1] != ')');
}

Node *parser(const char expression[], int *position, int *errorCode) {
    ++(*position);
    while (expression[*position] == ' ' || expression[*position] == '(' || expression[*position] == ')') {
        ++(*position);
    }

    Node *root = calloc(1, sizeof(Node));
    if (root == NULL) {
        *errorCode = -1;
        return NULL;
    }

    if (expression[*position] == '+' || expression[*position] == '-' || expression[*position] == '*' ||
        expression[*position] == '/') {
        if (expression[*position] == '-' && nextIsDigit(expression, *position)) {
            char *result = calloc(1, sizeof(char) * 8);
            if (result == NULL) {

                *errorCode = -1;
                return NULL;
            }

            int i = 2;
            result[0] = '-';
            result[1] = expression[(*position) + 1];
            ++(*position);
            while (nextIsDigit(expression, *position)) {
                result[i] = expression[(*position) + 1];
                ++(*position);
            }
            int intNumber = atoi(result);
            root->value = intNumber;
            free(result);
        } else {
            root->operation = expression[*position];
            root->rightChild = parser(expression, position, errorCode);
            root->leftChild = parser(expression, position, errorCode);
        }
    } else {
        char *number = malloc(sizeof(char) * 8);
        if (number == NULL) {
            *errorCode = -1;
            return NULL;
        }

        int i = 1;
        number[0] = expression[*position];
        while (nextIsDigit(expression, *position)) {
            number[i] = expression[(*position) + 1];
            (*position) += 1;
        }
        int intNumber = atoi(number);
        free(number);
        root->value = intNumber;
    }
    return root;
}

Tree *buildParseTree(char string[], int *errorCode) {
    Tree *temp = createTree(errorCode);
    if (*errorCode == -1) {
        return NULL;
    }

    int position = 0;
    temp->root = parser(string, &position, errorCode);
    if (*errorCode == -1) {
        removeTree(temp);
        return NULL;
    }
    return temp;
}

int calculateExpressionRecursion(Node *root) {
    if (root->operation == '+') {
        return calculateExpressionRecursion(root->leftChild) + calculateExpressionRecursion(root->rightChild);
    } else if (root->operation == '-') {
        return calculateExpressionRecursion(root->leftChild) - calculateExpressionRecursion(root->rightChild);
    } else if (root->operation == '*') {
        return calculateExpressionRecursion(root->leftChild) * calculateExpressionRecursion(root->rightChild);
    } else if (root->operation == '/') {
        return calculateExpressionRecursion(root->leftChild) / calculateExpressionRecursion(root->rightChild);
    } else {
        return root->value;
    }
}

int calculateExpression(Tree *tree) {
    return calculateExpressionRecursion(tree->root);
}

void freeTree(Node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->leftChild);
    freeTree(root->rightChild);
    free(root);
}

void removeTree(Tree *tree) {
    return freeTree(tree->root);
}