#include "tree.h"
#include <string.h>
#include <stdbool.h>

bool runAllTests() {
    int errorCode = 0;
    Dictionary *testDictionary = NULL;

    testDictionary = insert(testDictionary, 4, "qwerty", &errorCode);
    if (errorCode != 0) {
        freeDictionary(testDictionary);
        return false;
    }
    testDictionary = insert(testDictionary, 1, "wbwrw", &errorCode);
    if (errorCode != 0) {
        freeDictionary(testDictionary);
        return false;
    }
    testDictionary = insert(testDictionary, 10, "1314", &errorCode);
    if (errorCode != 0) {
        freeDictionary(testDictionary);
        return false;
    }

    if (!(isKeyInDictionary(testDictionary, 4) && isKeyInDictionary(testDictionary, 1) &&
          isKeyInDictionary(testDictionary, 10))) {
        freeDictionary(testDictionary);
        return false;
    }

    if (!(strcmp(getValue(testDictionary, 4), "qwerty") == 0 &&
          strcmp(getValue(testDictionary, 1), "wbwrw") == 0 &&
          strcmp(getValue(testDictionary, 10), "1314") == 0)) {
        freeDictionary(testDictionary);
        return false;
    }

    if (isKeyInDictionary(testDictionary, 100)) {
        freeDictionary(testDictionary);
        return false;
    }

    testDictionary = deleteElement(testDictionary, 1, &errorCode);
    if (errorCode != 0) {
        freeDictionary(testDictionary);
        return false;
    }

    if ((isKeyInDictionary(testDictionary, 1))) {
        freeDictionary(testDictionary);
        return false;
    }
    testDictionary = insert(testDictionary, 4, "-100", &errorCode);
    if (errorCode != 0) {
        freeDictionary(testDictionary);
        return false;
    }

    if (strcmp(getValue(testDictionary, 4), "-100") != 0) {
        freeDictionary(testDictionary);
        return false;
    }
    freeDictionary(testDictionary);
    return true;
}