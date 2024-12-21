#include <stdio.h>
#include <string.h>
#include "binarySearchTree.h"
#include "test.h"

#define SIZE 100

void showArray(const int array[], const int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
}

int getNumbers(int array[], int length) {
    char buffer[SIZE] = {'\0'};
    while (1) {
        fgets(buffer, SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        if (strlen(buffer) == 0) {
            break;
        }
        int number = atoi(buffer);
        if (length < SIZE) {
            array[length] = number;
            ++length;
        } else {
            printf("Error: out of range\n");
            break;
        }
    }
    return length;
}

int main() {
    if (!tests()) {
        printf("Tests failed, something went wrong");
        return -1;
    }
    printf("The tests were passed successfully\n");

    int array[SIZE] = {0};
    int length = 0;

    printf("Enter no more than 100 numbers\n");
    length = getNumbers(array, length);
    inOrderSort(array, length);
    printf("Your sorted array ");
    showArray(array, length);
    return 0;
}