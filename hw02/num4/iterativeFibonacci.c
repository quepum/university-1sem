#include <stdbool.h>
#include <stdio.h>

long long int iterativeMethod(int num) {
    long long int element1 = 0, element2 = 1;
    if (num == 1 || num == 2) {
        return 1;
    }
    else {
        for (int i = 2; i <= num; ++i) {
            long long int currentElement = element1 + element2;
            element1 = element2;
            element2 = currentElement;
        }
    }
    return element2;
}

bool test() {
    int currentSumm = 0;
    int correctAnswer = 17710;
    for (int i = 1; i <= 20; ++i) {
        currentSumm += iterativeMethod(i);
    }
    return correctAnswer == currentSumm;
}

int main(void) {
    if (!test()) {
        printf("%s", "Test failed");
        return 1;
    }

    int numberOfFibonacci = 0;

    printf("%s", "Enter how many fibonacci numbers you want to get\n");
    scanf("%d", &numberOfFibonacci);
    printf("%s", "Answer:\n");

    for (int i = 1; i <= numberOfFibonacci; ++i) {
        printf("%d.%lld\n",i, iterativeMethod(i));
    }
    return 0;
}

