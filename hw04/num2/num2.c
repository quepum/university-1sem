#include <stdio.h>
#include <stdbool.h>
#include "sort.h"

#define SIZE 100

int mostFrequentElement(const int array[], int length) {
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

bool test1() {
    int test1[10] = {1, 2, 1, 2, 2, 1, 1, 2, 1, 1};
    quickSort(test1, 0, 9);
    return mostFrequentElement(test1, 10) == 1;
}

bool test2() {
    int test2[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    return mostFrequentElement(test2, 10) == 1;
}

bool test3() {
    int test3[1] = {1};
    return mostFrequentElement(test3, 1) == 1;
}

void printer(int array[], const int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    if (!(tests() && test1() && test2() && test3())) {
        printf("Tests failed, something went wrong");
        return 1;
    } else {
        printf("%s", "The tests were passed successfully\n");
    }

    FILE *input = fopen("C:\\CLionProjects\\RepoGit1\\hw04\\num2\\inputData.txt", "r");
    if (input == NULL) {
        printf("File doesn't exist");
        return -1;
    }

    int collection[SIZE] = {0};
    int indexOfInputNumber = 0;
    while (fscanf(input, "%d", &collection[indexOfInputNumber]) != EOF) {
        ++indexOfInputNumber;
    }
    fclose(input);

    printf("Your collection is:\n");
    printer(collection, indexOfInputNumber);
    quickSort(collection, 0, indexOfInputNumber - 1);

    printf("The most frequent element in the array is: %d ", mostFrequentElement(collection, indexOfInputNumber));
    return 0;
}