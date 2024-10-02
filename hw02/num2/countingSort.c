#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void printer(int array[], const int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

int checkArrays(int array[]) {
    if (array == NULL) {
        return 1;
    }
    return 0;
}

int countingSort(const int length, int inputCollection[]) {
    int maxElement = inputCollection[0];
    for (int i = 1; i < length; ++i) {
        if (inputCollection[i] > maxElement) {
            maxElement = inputCollection[i];
        }
    }
    ++maxElement;

    int *indexList = calloc(maxElement, sizeof(long int));
    if (checkArrays(indexList) != 0) {
        printf("ERROR: memory is not available!\n");
        return 1;
    }

    for (int i = 0; i < length; ++i) {
        ++indexList[inputCollection[i]];
    }

    for (int i = 1; i <= maxElement; ++i) {
        indexList[i] += indexList[i - 1];
    }

    int *outputCollection = calloc(length, sizeof(long int));
    if (checkArrays(indexList) != 0) {
        printf("ERROR: memory is not available!\n");
        free(inputCollection);
        free(outputCollection);
        free(indexList);
        return 1;
    }

    for (int i = length - 1; i >= 0; --i) {
        outputCollection[indexList[inputCollection[i]] - 1] = inputCollection[i];
        --indexList[inputCollection[i]];
    }

    for (int i = 0; i < length; ++i) {
        inputCollection[i] = outputCollection[i];
    }

    free(outputCollection);
    free(indexList);

    return 0;
}

bool test1() {
    int testingArray[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    const int correctAnswer[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    countingSort(10, testingArray);
    for (int i = 0; i < 10; ++i) {
        if (testingArray[i] != correctAnswer[i]) {
            printf("test1");
            return false;
        }
    }
    return true;
}

bool test2() {
    int testingArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int correctAnswer[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    countingSort(10, testingArray);
    for (int i = 0; i < 10; ++i) {
        if (testingArray[i] != correctAnswer[i]) {
            printf("test2");
            return false;
        }
    }
    return true;
}

bool test3() {
    int testingArray[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    const int correctAnswer[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    countingSort(10, testingArray);
    for (int i = 0; i < 10; ++i) {
        if (testingArray[i] != correctAnswer[i]) {
            printf("test3");
            return false;
        }
    }
    return true;
}

int main(void) {

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
    int *collection = malloc(size * sizeof(long int));

    const int errorCode = checkArrays(collection);
    if (errorCode != 0) {
        printf("ERROR: memory is not available!\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        collection[i] = rand() % 1000;
    }

    printf("Before sorting:\n");
    printer(collection, size);

    countingSort(size, collection);

    printf("After sorting:\n");
    printer(collection, size);

    free(collection);

    return 0;
}
