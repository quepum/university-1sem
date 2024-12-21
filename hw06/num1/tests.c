#include "list.h"
#include <stdbool.h>

bool insertTest() {
    int errorCode = 0;
    List *test = createList(&errorCode);
    if (errorCode == -1) {
        return false;
    }
    insert(test, 0, 5, &errorCode);
    insert(test, 1, 9, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    int result1 = findPositionElement(test, 5);
    int result2 = findPositionElement(test, 9);
    removeList(test);
    return (result1 == 0 && result2 == 1);
}

bool orderInsertTest() {
    int errorCode = 0;
    List *test = createList(&errorCode);
    if (errorCode == -1) {
        return false;
    }
    addNewItemToList(test, 100, &errorCode);
    addNewItemToList(test, 0, &errorCode);
    addNewItemToList(test, -50, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    int result1 = findPositionElement(test, 100);
    int result2 = findPositionElement(test, -50);
    int result3 = findPositionElement(test, 0);
    removeList(test);
    return (result1 == 2 && result2 == 0 &&
            result3 == 1);
}

bool deleteElementTest() {
    int errorCode = 0;
    List *test = createList(&errorCode);
    insert(test, 0, 5, &errorCode);
    insert(test, 1, 10, &errorCode);
    insert(test, 2, 15, &errorCode);
    deleteElement(test, 1);
    int result = findPositionElement(test, 10);
    removeList(test);
    return (result == -1);
}

bool runAllTests() {
    return (deleteElementTest() && orderInsertTest() && insertTest());
}