#pragma once

typedef struct Node Node;
typedef struct Tree Tree;

// function that builds a tree based on the expression
Tree *buildParseTree(char string[], int *errorCode);

// function that evaluates expression by traversing the tree
int calculateExpression(Tree *tree);

// function that deletes tree
void removeTree(Tree *tree);