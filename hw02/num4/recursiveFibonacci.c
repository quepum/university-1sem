#include <stdbool.h>
#include <stdio.h>

long long int recursiveMethod(int num) {
    if (num == 1 || num == 2) {
        return 1;
    }
    return recursiveMethod(num - 1) + recursiveMethod(num - 2);
}

bool test() {
    int collectionFibonacci[10] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    for (int i = 1; i <= 10; ++i) {
        if (recursiveMethod(i) != collectionFibonacci[i - 1]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    if (!test()) {
        printf("%s", "Test failed");
        return 1;
    } else {
        printf("%s", "The tests were passed successfully\n");
    }

    int numberOfFibonacci = 0;

    printf("%s", "Enter how many fibonacci numbers you want to get:");
    scanf("%d", &numberOfFibonacci);

    while (numberOfFibonacci <= 0) {
        printf("Enter a natural number!\n");
        printf("%s", "Enter how many fibonacci numbers you want to get:");
        scanf("%d", &numberOfFibonacci);
    }

    printf("%s", "Answer:\n");
    for (int i = 1; i <= numberOfFibonacci; ++i) {
        printf("%d.%lld\n",i, recursiveMethod(i));
    }
    return 0;
}
