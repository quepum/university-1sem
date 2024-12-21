#include "binarySearchTree.h"
#include <stdbool.h>

const int size = 10;

bool isSorted(const int array[], const int length) {
    for (int i = 0; i < length - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

bool tests() {
    int test1[] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    inOrderSort(test1, size);
    if (!isSorted(test1, size)) {
        return false;
    }

    int test2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    inOrderSort(test2, size);
    if (!isSorted(test2, size)) {
        return false;
    }

    int test3[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    inOrderSort(test3, size);
    if (!isSorted(test3, size)) {
        return false;
    }

    int test4[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    inOrderSort(test4, size);
    if (!isSorted(test4, size)) {
        return false;
    }
    return true;
}