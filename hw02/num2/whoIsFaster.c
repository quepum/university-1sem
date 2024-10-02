#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

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

int main(void) {

    srand(time(0));
    int *collection1 = malloc(SIZE * sizeof(int));
    int *collection2 = malloc(SIZE * sizeof(int));

    if ((collection1 == NULL) || (collection2 == NULL)) {
        printf("ERROR: memory is not available!\n");
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        int element = rand() % 100000;
        collection1[i] = element;
        collection2[i] = element;
    }

    const double timeOfStartingBubbleMethod = clock();
    bubbleSort(collection1, SIZE);
    const double timeOfEndingBubbleMethod = clock();
    free(collection1);

    const double timeOfStartingCountingMethod = clock();
    countingSort(SIZE, collection2);
    const double timeOfEndingCountingMethod = clock();
    free(collection2);

    double timeBubble = (timeOfEndingBubbleMethod - timeOfStartingBubbleMethod)/CLOCKS_PER_SEC;
    double timeCounting = (timeOfEndingCountingMethod - timeOfStartingCountingMethod)/CLOCKS_PER_SEC;

    printf("Bubble sorting: %f\nCounting sorting: %f\n",timeBubble, timeCounting);
    printf("%s", "The first one is slower");
    return 0;
}
