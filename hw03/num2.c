#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_SIZE 10

int binarySearch(const int inputCollection[], int left, int right, int number) {
    if (left <= right) {
        int index = (left + right) / 2;
        if (inputCollection[index] == number) {
            return index;
        }
        if (number > inputCollection[index]) {
            return binarySearch(inputCollection, index + 1, right, number);
        }
        if (number < inputCollection[index]) {
            return binarySearch(inputCollection, left, index - 1, number);
        }
    }
    return -1;
}

void swap(int *firstValue, int *secondValue) {
    int copy = *firstValue;
    *firstValue = *secondValue;
    *secondValue = copy;
}

void insertionSort(int arr[], const int low, const int high) {
    for (int i = low; i < high; ++i) {
        const int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] >= key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void quickSort(int inputCollection[], const int low, int high) {
    if (high - low + 1 < 10) {
        insertionSort(inputCollection, low, high + 1);
        return;
    }
    int pivot = inputCollection[high];
    int i = low;
    for (int j = low; j < high; ++j) {
        if (inputCollection[j] <= pivot) {
            swap(&inputCollection[i], &inputCollection[j]);
            ++i;
        }
    }
    swap(&inputCollection[i], &inputCollection[high]);
    quickSort(inputCollection, low, i - 1);
    quickSort(inputCollection, i + 1, high);
}

void printer(int array[], const int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

void generatorOfNumbers(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

bool checkSorting(const int testingArray[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (testingArray[i] > testingArray[i + 1]) {
            return false;
        }
    }
    return true;
}

bool test1() {
    int collectionForTesting[TEST_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    quickSort(collectionForTesting, 0, TEST_SIZE - 1);
    return checkSorting(collectionForTesting, TEST_SIZE);
}

bool test2() {
    int collectionForTesting[TEST_SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    quickSort(collectionForTesting, 0, TEST_SIZE - 1);
    return checkSorting(collectionForTesting, TEST_SIZE);
}

bool test3() {
    int collectionForTesting[TEST_SIZE] = {1, 3, 7, 2, 4, 6, 9, 1, 1, 100};
    quickSort(collectionForTesting, 0, TEST_SIZE - 1);
    return checkSorting(collectionForTesting, TEST_SIZE);
}

bool test4() {
    int collectionForTesting[TEST_SIZE] = {100, 3, 7, 2, 4, 6, 9, 1, 1, 0};
    quickSort(collectionForTesting, 0, TEST_SIZE - 1);
    return checkSorting(collectionForTesting, TEST_SIZE);
}

bool test5() {
    const int collectionForTesting[TEST_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int correctAnswer = 0;
    return binarySearch(collectionForTesting, 0, TEST_SIZE - 1, 1) == correctAnswer;
}

bool test6() {
    const int collectionForTesting[TEST_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int correctAnswer = 9;
    return binarySearch(collectionForTesting, 0, TEST_SIZE - 1, 10) == correctAnswer;
}

bool test7() {
    const int collectionForTesting[TEST_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int correctAnswer = -1;
    return binarySearch(collectionForTesting, 0, TEST_SIZE - 1, 35) == correctAnswer;
}

int main(void) {
    if (!(test1() && test2() && test3() && test4() && test5() && test6() && test7())) {
        printf("Tests failed, something went wrong");
        return 1;
    } else {
        printf("%s", "The tests were passed successfully\n");
    }

    int n = 0;
    int k = 0;
    printf("Enter the length of the array and amount of numbers for checking\n");
    scanf("%d%d", &n, &k);
    while (n <= 0 || k <= 0) {
        printf("Enter the length of the array and amount of numbers for checking\n");
        scanf("%d%d", &n, &k);
    }

    srand(time(NULL));
    int *collectionForSearching = malloc(n * sizeof(int));
    int *collectionOfNumbers = malloc(k * sizeof(int));

    if (collectionOfNumbers == NULL || collectionForSearching == NULL) {
        printf("ERROR: memory is not available!\n");
        return 1;
    }
    generatorOfNumbers(collectionForSearching, n);
    generatorOfNumbers(collectionOfNumbers, k);
    quickSort(collectionForSearching, 0, n - 1);

    printf("Generated numbers:\n");
    printer(collectionOfNumbers, k);
    printf("Generated array:\n");
    printer(collectionForSearching, n);

    for (int i = 0; i < k; ++i) {
        if (binarySearch(collectionForSearching, 0, n - 1, collectionOfNumbers[i]) != -1) {
            printf("%d in the array\n", collectionOfNumbers[i]);
        }
    }
    free(collectionOfNumbers);
    free(collectionForSearching);
    return 0;
}
