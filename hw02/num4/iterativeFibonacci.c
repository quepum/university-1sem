#include <stdbool.h>
#include <stdio.h>

long long int iterativeMethod(const int num) {
    long long int element1 = 0;
    long long element2 = 1;
    if (num == 1 || num == 2) {
        return 1;
    } else {
        for (int i = 2; i <= num; ++i) {
            long long int currentElement = element1 + element2;
            element1 = element2;
            element2 = currentElement;
        }
    }
    return element2;
}

bool test() {
    const int collectionFibonacci[10] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    for (int i = 1; i <= 10; ++i) {
        if (iterativeMethod(i) != collectionFibonacci[i - 1]) {
            return false;
        }
    }
    return true;
}

int checkInput(const int num) {
    if (num <= 0 || num > 60) {
        return 1;
    }
    return 0;
}

int main(void) {
    if (!test()) {
        printf("%s", "Test failed");
        return 1;
    } else {
        printf("%s", "The tests were passed successfully\n");
    }

    int numberOfFibonacci = 0;

    printf("%s", "Enter how many fibonacci numbers you want to get(no more than 60):");
    scanf("%d", &numberOfFibonacci);

    int errorCode = checkInput(numberOfFibonacci);
    while (errorCode != 0) {
        printf("Enter a natural number no more than 60!\n");
        printf("%s", "Enter how many fibonacci numbers you want to get:");
        scanf("%d", &numberOfFibonacci);
        errorCode = checkInput(numberOfFibonacci);
    }

    printf("%s", "Answer:\n");

    for (int i = 1; i <= numberOfFibonacci; ++i) {
        printf("%d.%lld\n",i, iterativeMethod(i));
    }
    return 0;
}
