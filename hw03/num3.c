#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_SIZE 100

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

bool test1(){
    int *collectionForTesting = malloc(TEST_SIZE * sizeof(int));
    if (collectionForTesting == NULL) {
        printf("ERROR: memory is not available!\n");
        return false;
    }
    for (int i = 0; i < TEST_SIZE; i++) {
        collectionForTesting[i] = rand() % 100;
    }
    quickSort(collectionForTesting, 0, TEST_SIZE - 1);
    if (!checkSorting(collectionForTesting, TEST_SIZE)) {
        free(collectionForTesting);
        return false;
    }
    free(collectionForTesting);
    return true;
}

bool test2() {
    int collectionForTesting[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    quickSort(collectionForTesting, 0, 9);
    return checkSorting(collectionForTesting, 10);
}

bool test3() {
    int collectionForTesting[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    quickSort(collectionForTesting, 0, 9);
    return checkSorting(collectionForTesting, 10);
}

bool test4() {
    int collectionForTesting[10] = {1, 3, 7, 2, 4, 6, 9, 1, 1, 100};
    quickSort(collectionForTesting, 0, 9);
    return checkSorting(collectionForTesting, 10);
}

bool test5() {
    int collectionForTesting[10] = {100, 3, 7, 2, 4, 6, 9, 1, 1, 0};
    quickSort(collectionForTesting, 0, 9);
    return checkSorting(collectionForTesting, 10);
}

void printer(int array[], const int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

int main() {
    if (!(test1() && test2() && test3() && test4() && test5())) {
        printf("Tests failed, something went wrong");
        return 1;
    } else {
        printf("%s", "The tests were passed successfully\n");
    }

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
