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

void quickSort(int inputCollection[], const int low, const int high) {
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
