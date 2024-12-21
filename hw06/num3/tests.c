#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

bool isSorted(Record *head, const int sortByName) {
    if (sortByName == 1) {
        Record *temp = head;
        while (temp->next != NULL) {
            if (strcmp(temp->name, temp->next->name) > 0) {
                return false;
            }
            temp = temp->next;
        }
        return true;
    } else {
        Record *temp = head;
        while (temp->next != NULL) {
            if (temp->phone > temp->next->phone) {
                return false;
            }
            temp = temp->next;
        }
        return true;
    }
}

bool testWithSameRecords() {
    int errorCode = 0;
    Record *head = NULL;
    appendRecord(&head, "Tom", "111", &errorCode);
    appendRecord(&head, "Tom", "111", &errorCode);
    appendRecord(&head, "Tom", "111", &errorCode);
    if (errorCode == -1) {
        return false;
    }
    mergeSort(head, 1);
    if (!isSorted(head, 1)) {
        return false;
    }
    mergeSort(head, 0);
    if (!isSorted(head, 0)) {
        return false;
    }
    removeList(head);
    return true;
}

bool testWithUsualData() {
    int errorCode = 0;
    Record *head = NULL;
    appendRecord(&head, "Henry", "343", &errorCode);
    appendRecord(&head, "Olga", "2", &errorCode);
    appendRecord(&head, "Ann", "11", &errorCode);
    if (errorCode == -1) {
        return false;
    }
    mergeSort(head, 1);
    if (!isSorted(head, 1)) {
        return false;
    }
    mergeSort(head, 0);
    if (!isSorted(head, 0)) {
        return false;
    }
    removeList(head);
    return true;
}

bool runTests() {
    return testWithSameRecords() && testWithUsualData();
}