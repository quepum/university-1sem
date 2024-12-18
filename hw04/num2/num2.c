#include <stdio.h>
#include <malloc.h>
#include "sort.h"
#include "tests.h"

int getMostFrequentElement(const int array[], int length) {
    int mostFrequent = array[0];
    int count = 1;
    int maxCount = 1;

    for (int i = 1; i < length; ++i) {
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

void printArray(int array[], const int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    if (!runAllTests()) {
        printf("Tests failed, something went wrong");
        return 1;
    }
    printf("%s", "Tests were passed successfully\n");

    FILE *input = fopen("hw04/num2/inputData.txt", "r");
    if (input == NULL) {
        printf("File doesn't exist");
        return -1;
    }

    int indexOfInputNumber = 0;
    int size = 0;
    fscanf(input, "%d", &size);
    int *collection = calloc(1, size * sizeof(int));

    while (fscanf(input, "%d", &collection[indexOfInputNumber]) != EOF) {
        ++indexOfInputNumber;
    }
    fclose(input);

    printf("Your collection is:\n");
    printArray(collection, size);
    quickSort(collection, 0, size - 1);
    printf("The most frequent element in the array is: %d ", getMostFrequentElement(collection, size));

    free(collection);
    return 0;
}