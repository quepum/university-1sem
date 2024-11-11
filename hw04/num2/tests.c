#include <stdbool.h>
#include "sort.h"

bool checkSorting(const int testingArray[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (testingArray[i] > testingArray[i + 1]) {
            return false;
        }
    }
    return true;
}

bool sortingTests() {
    int collectionForTesting1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    quickSort(collectionForTesting1, 0, 9);
    if (!(checkSorting(collectionForTesting1, 10) ? true : false)) {
        return false;
    }

    int collectionForTesting2[1] = {1};
    quickSort(collectionForTesting2, 0, 0);
    if (!(checkSorting(collectionForTesting2, 1) ? true : false)) {
        return false;
    }

    int collectionForTesting3[10] = {1, 3, -7, 2, 4, 6, -9, 1, 1, 100};
    quickSort(collectionForTesting3, 0, 9);
    if (!(checkSorting(collectionForTesting3, 10) ? true : false)) {
        return false;
    }

    int collectionForTesting4[10] = {100, 3, 7, 2, 4, 6, 9, 1, 1, 0};
    quickSort(collectionForTesting4, 0, 9);
    if (!(checkSorting(collectionForTesting4, 10) ? true : false)) {
        return false;
    }
    return true;
}

bool testNormalSituation() {
    int test[10] = {1, 2, 1, 2, 2, 1, 1, 2, 1, 1};
    quickSort(test, 0, 9);
    return mostFrequentElement(test, 10) == 1;
}

bool testWithIdenticalElements() {
    int test[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    return mostFrequentElement(test, 10) == 1;
}

bool testWithOneElement() {
    int test[1] = {1};
    return mostFrequentElement(test, 1) == 1;
}

bool testWithoutRepeats() {
    int test[10] = {15, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    return mostFrequentElement(test, 10) == 15;
}

bool allTests() {
    return (sortingTests() && testNormalSituation() && testWithIdenticalElements() && testWithOneElement() &&
            testWithoutRepeats());
}