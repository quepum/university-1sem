#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
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

Tree *createTree() {
    Tree *tree = calloc(1, sizeof(Tree));
    assert(tree != NULL && "Memory error\n");
    tree->root = NULL;
    return tree;
}

bool nextIsDigit(const char expression[], int position) {
    return (expression[position + 1] != ' ' && expression[position + 1] != '+' && expression[position + 1] != '*' &&
            expression[position + 1] != '/' && expression[position + 1] != '(' && expression[position + 1] != ')');
}

Node *parser(const char expression[], int *position) {
    ++(*position);
    while (expression[*position] == ' ' || expression[*position] == '(' || expression[*position] == ')') {
        ++(*position);
    }

    Node *root = calloc(1, sizeof(Node));
    assert(root != NULL && "Memory error");

    if (expression[*position] == '+' || expression[*position] == '-' || expression[*position] == '*' ||
        expression[*position] == '/') {
        if (expression[*position] == '-' && nextIsDigit(expression, *position)) {
            char *result = calloc(1, sizeof(char) * 8);
            assert(result != NULL && "Memory error");
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
        } else {
            root->operation = expression[*position];
            root->rightChild = parser(expression, position);
            root->leftChild = parser(expression, position);
        }
    } else {
        char *number = malloc(sizeof(char) * 8);
        int i = 1;
        number[0] = expression[*position];
        while (nextIsDigit(expression, *position)) {
            number[i] = expression[(*position) + 1];
            (*position) += 1;
        }
        int intNumber = atoi(number);
        root->value = intNumber;
    }
    return root;
}

Tree *buildParseTree(char string[]) {
    Tree *temp = createTree();
    int position = 0;
    temp->root = parser(string, &position);
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
