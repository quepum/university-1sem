#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"

bool tests() {
    Node *root = NULL;
    root = insert(root, "qwerty", "123");
    root = insert(root, "acsd", "cvvc");
    root = insert(root, "-12389", "we w323cfd");

    if (!(isKeyInTree(root, "qwerty") && isKeyInTree(root, "acsd") && isKeyInTree(root, "-12389"))) {
        freeAVL(root);
        return false;
    }
    if (isKeyInTree(root, "00000")) {
        freeAVL(root);
        return false;
    }
    if (strcmp(getValue(root, "acsd")->value, "cvvc") != 0) {
        freeAVL(root);
        return false;
    }
    if (getValue(root, "q2ee") != NULL) {
        freeAVL(root);
        return false;
    }
    root = insert(root, "qwerty", "bnb e2");
    if (strcmp(getValue(root, "qwerty")->value, "bnb e2") != 0) {
        freeAVL(root);
        return false;
    }
    root = deleteNode(root, "-12389");
    if (isKeyInTree(root, "-12389")) {
        freeAVL(root);

        return false;
    }
    freeAVL(root);
    return true;
}