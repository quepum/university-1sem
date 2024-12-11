#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST_SIZE 10

void findMaxAndMinElements(const int inputCollection[], const int length, int *minElement, int *maxElement) {
    for (int i = 1; i < length; ++i) {
        if (inputCollection[i] < *minElement) {
            *minElement = inputCollection[i];
        }
        if (inputCollection[i] > *maxElement) {
            *maxElement = inputCollection[i];
        }
    }
}

int mostFrequentElement(const int inputCollection[], const int length) {
    if (length == 1)
        return inputCollection[0];

    int minElement = inputCollection[0];
    int maxElement = inputCollection[0];
    findMaxAndMinElements(inputCollection, length, &minElement, &maxElement);

    int offset = (minElement < 0) ? -minElement : 0;
    int range = maxElement - minElement + 2;
    int *indexList = calloc(range, sizeof(int));
    if (indexList == NULL) {
        printf("ERROR: memory is not available!\n");
        return -1;
    }
    for (int i = 0; i < length; ++i) {
        ++indexList[inputCollection[i] + offset];
    }

    int mostFrequentElement = 0;
    int maxCount = 0;
    for (int i = 0; i < range; ++i) {
        int currentElement = i - offset;
        if (indexList[currentElement + offset] >= maxCount) {
            mostFrequentElement = currentElement;
            maxCount = indexList[currentElement + offset];
        }
    }
    free(indexList);
    return mostFrequentElement;
}

bool allTests() {
    int test1[TEST_SIZE] = {1, 2, 2, 2, 3, 3, 3, 3, 3, 3};
    if (mostFrequentElement(test1, TEST_SIZE) != 3) {
        printf("1");
        return false;
    }

    int test2[TEST_SIZE] = {4, 4, 1, 4, 1, 2, 3, 3, 2, 3};
    if (mostFrequentElement(test2, TEST_SIZE) != 4) {
        printf("2");
        return false;
    }

    int test3[1] = {1};
    if (mostFrequentElement(test3, 1) != 1) {
        printf("3");
        return false;
    }

    int test4[TEST_SIZE] = {-2, -1, -1, -2, -2, 0, -2, -2, -1, -2};
    if (mostFrequentElement(test4, TEST_SIZE) != -2) {
        printf("4");
        return false;
    }

    int test5[TEST_SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    if (mostFrequentElement(test5, TEST_SIZE) != 1) {
        printf("5");
        return false;
    }

    int test6[TEST_SIZE] = {1, 8, 6, 3, 5, 4, 2, 7, 9, 0};
    if (mostFrequentElement(test6, TEST_SIZE) != 9) {
        printf("6");
        return false;
    }
    return true;
}

int main(void) {
    if (!allTests()) {
        printf("Tests failed, something went wrong");
        return -1;
    }
    printf("All tests were passed successfully\n");

    int size = 0;
    printf("Enter the size of the array:\n");
    scanf("%d", &size);
    while (size <= 0) {
        printf("Enter a natural number, try again!\n");
        printf("Enter the size of the array:\n");
        scanf("%d", &size);
    }

    int *collection = malloc(size * sizeof(int));
    if (collection == NULL) {
        printf("ERROR: memory is not available!\n");
        return 1;
    }
    for (int i = 0; i < size; ++i) {
        scanf("%d", &collection[i]);
    }

    printf("The most frequent element is %d", mostFrequentElement(collection, size));
    free(collection);
    return 0;
}
