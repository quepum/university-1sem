#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_SIZE 10

void shellSort(int inputCollection[], const int size) {
    const int step = size / 2;
    for (int i = step; i > 0; i /= 2) {
        for (int j = i; j < size; j += 1) {
            const int copy = inputCollection[j];
            int k;
            for (k = j; k >= i && inputCollection[k - i] > copy; k -= i) {
                inputCollection[k] = inputCollection[k - i];
            }
            inputCollection[k] = copy;
        }
    }
}

void printer(int array[], const int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

bool test1() {
    int testingArray[TEST_SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    const int correctAnswer[TEST_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    shellSort(testingArray, TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; ++i) {
        if (testingArray[i] != correctAnswer[i]) {
            return false;
        }
    }
    return true;
}

bool test2() {
    int testingArray[TEST_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int correctAnswer[TEST_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    shellSort(testingArray, TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; ++i) {
        if (testingArray[i] != correctAnswer[i]) {
            return false;
        }
    }
    return true;
}

bool test3() {
    int testingArray[TEST_SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    const int correctAnswer[TEST_SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    shellSort(testingArray, TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; ++i) {
        if (testingArray[i] != correctAnswer[i]) {
            return false;
        }
    }
    return true;
}

int main() {

    if (!(test1() && test2() && test3())) {
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

    shellSort(collection, size);

    printf("After sorting\n");
    printer(collection, size);

    free(collection);
    return 0;
}
