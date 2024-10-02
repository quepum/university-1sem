#include <stdio.h>
#include <stdbool.h>

void swap(int *firstValue, int *secondValue) {
    int copy = *firstValue;
    *firstValue = *secondValue;
    *secondValue = copy;
}

void bubbleSort(int array[], const int length, int *errorCode) {
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length - 1; ++j) {
            if(array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void printer(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

bool test1() {
    int testingArray[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    const int correctAnswer[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bubbleSort(testingArray, 10, 0);
}

int main(void) {
    int collection[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int errorCode = 0;
    bubbleSort(collection, 10, &errorCode);
    if (errorCode != 0) {
        printf("%s", 'Incorrect input');
        return 1;
    }
    printer(collection, 10);
    return 0;
}

