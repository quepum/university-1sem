#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    int *indexList = calloc(maxElement, sizeof(int));
    if (checkArrays(indexList) != 0) {
        printf("ERROR: memory is not available!\n");
        return 1;
    }

    for (int i = 0; i < length; ++i) {
        ++indexList[inputCollection[i]];
    }

    for (int i = 1; i < maxElement; ++i) {
        indexList[i] += indexList[i - 1];
    }

    int *outputCollection = malloc(length * sizeof(int));
    if (checkArrays(outputCollection) != 0) {
        printf("ERROR: memory is not available!\n");
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

int mostFrequentElement(int array[], int length) {
    countingSort(length, array);
    int mostFrequent = array[0];
    int count = 1;
    int maxCount = 1;

    for (int i = 1; i < length - 1; ++i) {
        if (array[i] == array[i - 1]) {
            ++count;
            if (count > maxCount) {
                maxCount = count;
                mostFrequent = array[i];
            }
        } else {
            count = 1;
        }
    }
    return mostFrequent;
}

void printer(int array[], const int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

bool test1() {
    int test1[10] = {1, 2, 1, 2, 2, 1, 1, 2, 1, 1};
    return mostFrequentElement(test1, 10) == 1;
}

bool test2() {
    int test2[10] = {1};
    return mostFrequentElement(test2, 10) == 1;
}

bool test3() {
    int test3[1] = {1};
    return mostFrequentElement(test3, 10) == 1;
}

int main(void) {
    if (test1() && test2() && test3()) {
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

    printf("Your collection is\n");
    printer(collection, size);

    printf("%d", mostFrequentElement(collection, size));

    free(collection);
    return 0;
}
