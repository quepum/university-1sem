#include <stdbool.h>
#include <stdio.h>
#include "list.h"

bool listsAreEqual(List *list1, List *list2) {
    Node *current1 = list1->head;
    Node *current2 = list2->head;

    while (current1 != NULL && current2 != NULL) {
        if (current1->value != current2->value) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return true;
}

bool testNoElements() {
    int errorCode = 0;
    List *list = createNewList(&errorCode);
    if (errorCode == -1) return -1;

    deleteOddIndexes(list);
    if (errorCode == -1) {
        deleteList(list);
        return false;
    }
    deleteList(list);
    return true;
}

bool testOneElement() {
    int errorCode = 0;

    List *list = createNewList(&errorCode);
    if (errorCode == -1) return false;
    int elements[] = {1};
    addNewElement(list, elements[0], &errorCode);
    if (errorCode == -1) {
        deleteList(list);
        return false;
    }
    deleteOddIndexes(list);

    List *expectedAnswer = createNewList(&errorCode);
    if (errorCode == -1) return false;
    addNewElement(list, 1, &errorCode);
    if (errorCode == -1) {
        deleteList(list);
        return false;
    }

    if (!listsAreEqual(list, expectedAnswer)) {
        deleteList(list);
        deleteList(expectedAnswer);
        return false;
    }
    deleteList(list);
    deleteList(expectedAnswer);
    return true;
}

bool testNormalData() {
    int errorCode = 0;

    List *list = createNewList(&errorCode);
    if (errorCode == -1) return false;
    int elements[] = {6, 5, 4, 3, 2, 1};
    for (int i = 0; i < 6; ++i) {
        addNewElement(list, elements[i], &errorCode);
        if (errorCode == -1) {
            deleteList(list);
            return false;
        }
    }
    deleteOddIndexes(list);

    List *expectedAnswer = createNewList(&errorCode);
    if (errorCode == -1) return false;
    int correctAnswer[] = {5, 3, 1};
    for (int i = 0; i < 3; ++i) {
        addNewElement(list, correctAnswer[i], &errorCode);
        if (errorCode == -1) {
            deleteList(list);
            deleteList(expectedAnswer);
            return false;
        }
    }

    if (!listsAreEqual(list, expectedAnswer)) {
        deleteList(list);
        deleteList(expectedAnswer);
        return false;
    }
    deleteList(list);
    deleteList(expectedAnswer);
    return true;
}

bool runAllTests() {
    return testNoElements() && testOneElement() && testNormalData();
}