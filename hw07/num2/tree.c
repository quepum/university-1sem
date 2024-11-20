#include <stdlib.h>
#include <assert.h>

typedef struct Node {
    int data;
    char operation;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Tree {
    Node *root;
} Tree;

Node *parser() {

}


Tree* createParseTree() {
    Tree* tree = calloc(1, sizeof(Tree));
    assert(tree != NULL && "Memory error\n");
    tree->root = NULL;
    return tree;
}

Tree* buildTree(char string[]) {
    Tree* tmp = createParseTree();
    int position = 0;
    tmp->root = parser(string, &position);
    return tmp;
}