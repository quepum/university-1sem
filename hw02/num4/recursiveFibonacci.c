#include <stdbool.h>
#include <stdio.h>

long long int recursiveMethod(int num) {
    if (num == 1 || num == 2) {
        return 1;
    }
    return recursiveMethod(num - 1) + recursiveMethod(num - 2);
}

bool test() {
    int currentSumm = 0;
    int correctAnswer = 17710;
    for (int i = 1; i <= 20; ++i) {
        currentSumm += recursiveMethod(i);
    }
    return correctAnswer == currentSumm;
}

int main(void) {
    if (!test()) {
        printf("%s", "Test failed");
        return 1;
    }

    int numberOfFibonacci = 0;

    printf("%s", "Enter how many fibonacci numbers you want to get:");
    scanf("%d", &numberOfFibonacci);
    printf("%s", "Answer:\n");

    for (int i = 1; i <= numberOfFibonacci; ++i) {
        printf("%d.%lld\n",i, recursiveMethod(i));
    }
    return 0;
}
