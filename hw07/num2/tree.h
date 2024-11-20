#pragma once

typedef struct Node Node;
typedef struct Tree Tree;

Tree *buildParseTree(char string[]);

int calculateExpression(Tree *tree);

void deleteParseTree(Tree *ParseTree);