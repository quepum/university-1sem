#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void swap(int *firstValue, int *secondValue) {
    int copy = *firstValue;
    *firstValue = *secondValue;
    *secondValue = copy;
}

int bubbleSort(int array[], const int length) {
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length - 1; ++j) {
            if(array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
    return 0;
}

void printer(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

int checkInput(int array[]) {
    if (array == NULL) {
        return 1;
    }
    return 0;
}

bool test1() {
    int testingArray[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    const int correctAnswer[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bubbleSort(testingArray, 10);
    for (int i = 0; i < 10; ++i) {
        if (testingArray[i] != correctAnswer[i]) {
            return false;
        }
    }
    return true;
}

bool test2() {
    int testingArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int correctAnswer[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bubbleSort(testingArray, 10);
    for (int i = 0; i < 10; ++i) {
        if (testingArray[i] != correctAnswer[i]) {
            return false;
        }
    }
    return true;
}

bool test3() {
    int testingArray[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    const int correctAnswer[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    bubbleSort(testingArray, 10);
    for (int i = 0; i < 10; ++i) {
        if (testingArray[i] != correctAnswer[i]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    if(!(test1() && test2() && test3())) {
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
    for (int i = 0; i < size; i++) {
        collection[i] = rand() % 1000;
    }

    const int errorCode = checkInput(collection);
    if (errorCode != 0) {
        printf("ERROR: memory is not available!\n");
        free(collection);
        return 1;
    }

    printf("Before sorting:\n");
    printer(collection, size);

    bubbleSort(collection, size);

    printf("After sorting:\n");
    printer(collection, size);

    free(collection);
    return 0;
}
