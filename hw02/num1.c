#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 1000
#define TEST_SIZE 10

void swap(int *firstValue, int *secondValue) {
    int copy = *firstValue;
    *firstValue = *secondValue;
    *secondValue = copy;
}

void sortingArray(int array[], int endIndex, int startIndex) {
    int key = array[startIndex];
    int pointerHighNumber = startIndex + 1;

    for (int i = 1; i <= endIndex; ++i) {
        if (array[i] < key) {
            swap(&array[pointerHighNumber], &array[i]);
            ++pointerHighNumber;
        }
    }
    swap(&array[pointerHighNumber - 1], &array[0]);
}

void printer(int array[]) {
    for (int i = 0; i < SIZE; ++i) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

bool test() {
    int collectionForTesting[TEST_SIZE] = {0};

    for (int i = 0; i < TEST_SIZE; ++i) {
        collectionForTesting[i] = rand() % 21;
    }

    int key = collectionForTesting[0];
    sortingArray(collectionForTesting, TEST_SIZE - 1, 0);
    int borderIndex = 0;
    while (collectionForTesting[borderIndex] != key) {
        if (collectionForTesting[borderIndex] >= key) {
            return false;
        }
        ++borderIndex;
    }
    for (int i = borderIndex; i < TEST_SIZE; ++i) {
        if (collectionForTesting[i] < key) {
            return false;
        }
    }
    return true;
}

int main(void) {

    if (!test()) {
        printf("Test failed");
        return 1;
    }

    srand(time(0));

    int collection[SIZE] = {0};
    for (int i = 0; i < SIZE; ++i) {
        collection[i] = rand() % 2000;
    }

    printf("Before sorting:\n");
    printer(collection);

    sortingArray(collection, SIZE - 1, 0);

    printf("After sorting:\n");
    printer(collection);
    return 0;
}
