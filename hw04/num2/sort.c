#include <stdbool.h>
#include <stdio.h>
#include "sort.h"

void swap(int *firstValue, int *secondValue) {
    int copy = *firstValue;
    *firstValue = *secondValue;
    *secondValue = copy;
}

void insertionSort(int arr[], const int low, const int high) {
    for (int i = low; i < high; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] >= key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void quickSort(int inputCollection[], const int low, int high) {
    if (high - low + 1 < 10) {
        insertionSort(inputCollection, low, high + 1);
        return;
    }
    int pivot = inputCollection[high];
    int i = low;
    for (int j = low; j < high; ++j) {
        if (inputCollection[j] <= pivot) {
            swap(&inputCollection[i], &inputCollection[j]);
            ++i;
        }
    }
    swap(&inputCollection[i], &inputCollection[high]);
    quickSort(inputCollection, low, i - 1);
    quickSort(inputCollection, i + 1, high);
}

bool checkSorting(const int testingArray[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (testingArray[i] > testingArray[i + 1]) {
            return false;
        }
    }
    return true;
}

bool tests() {
    int collectionForTesting1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    quickSort(collectionForTesting1, 0, 9);
    if (!(checkSorting(collectionForTesting1, 10) ? true : false)) {
        return false;
    }

    int collectionForTesting2[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    quickSort(collectionForTesting2, 0, 9);
    if (!(checkSorting(collectionForTesting2, 10) ? true : false)) {
        return false;
    }

    int collectionForTesting3[10] = {1, 3, 7, 2, 4, 6, 9, 1, 1, 100};
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
