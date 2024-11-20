#include <assert.h>
#include "tree.h"
#include <string.h>

void tests() {
    Dictionary *testDictionary = createDictionary();

    insert(testDictionary, 4, "qwerty");
    insert(testDictionary, 1, "wbwrw");
    insert(testDictionary, 10, "1314");

    assert((isKeyInTheDictionary(testDictionary, 4) && isKeyInTheDictionary(testDictionary, 1) &&
            isKeyInTheDictionary(testDictionary, 10)) && "Error adding a value");
    assert((strcmp(getValue(testDictionary, 4), "qwerty") == 0 &&
            strcmp(getValue(testDictionary, 1), "wbwrw") == 0 &&
            strcmp(getValue(testDictionary, 10), "1314") == 0) && "Key value access error\n");
    assert(!(isKeyInTheDictionary(testDictionary, 100)) && "Error verifying the existence of the key\n");
    removeKey(testDictionary, 1);
    assert(!(isKeyInTheDictionary(testDictionary, 1)) && "Key deletion error\n");
    changeData(testDictionary, 4, "-100");
    assert(strcmp(getValue(testDictionary, 4), "-100") == 0 && "Error changing the key value\n");
    deleteDictionary(testDictionary);
}