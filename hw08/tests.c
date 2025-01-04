#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"

bool tests() {
    Dictionary *root = NULL;
    int errorCode = 0;
    root = insert(root, "qwerty", "123", &errorCode);
    if (!isAVL(root) || errorCode != 0) {
        freeTree(root);
        return false;
    }

    root = insert(root, "acsd", "cvvc", &errorCode);
    if (!isAVL(root) || errorCode != 0) {
        freeTree(root);
        return false;
    }

    root = insert(root, "-12389", "we w323cfd", &errorCode);
    if (!isAVL(root) || errorCode != 0) {
        freeTree(root);
        return false;
    }

    if (!(isKeyInTree(root, "qwerty") && isKeyInTree(root, "acsd") && isKeyInTree(root, "-12389"))) {
        freeTree(root);
        return false;
    }
    if (isKeyInTree(root, "00000")) {
        freeTree(root);
        return false;
    }

    if (strcmp(getValue(root, "acsd"), "cvvc") != 0) {
        freeTree(root);
        return false;
    }
    if (getValue(root, "q2ee") != NULL) {
        freeTree(root);
        return false;
    }

    root = insert(root, "qwerty", "bnb e2", &errorCode);
    if (!isAVL(root) || errorCode != 0) {
        freeTree(root);
        return false;
    }

    if (strcmp(getValue(root, "qwerty"), "bnb e2") != 0) {
        freeTree(root);
        return false;
    }
    root = deleteNode(root, "-12389");
    if (!isAVL(root)) {
        freeTree(root);
        return false;
    }
    if (isKeyInTree(root, "-12389")) {
        freeTree(root);
        return false;
    }
    freeTree(root);
    return true;
}