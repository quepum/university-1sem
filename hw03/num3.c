#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void printer(int array[], const int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

int main() {
    int size = 0;
    printf("Enter the size of the array:\n");
    scanf("%d", &size);

    while (size <= 0) {
        printf("Enter a natural number, try again!\n");
        printf("Enter the size of the array:\n");
        scanf("%d", &size);
    }

    srand(time(0));
    int *collection = malloc(size * sizeof(int));

    if (collection == NULL) {
        printf("ERROR: memory is not available!\n");
        return 1;
    }
    for (int i = 0; i < size; i++) {
        collection[i] = rand() % 100;
    }

    printf("Before sorting\n");
    printer(collection, size);

    quickSort(collection, 0, size - 1);

    printf("After sorting\n");
    printer(collection, size);

    free(collection);
    return 0;
}
