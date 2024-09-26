#include <stdio.h>
#include <time.h>

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

long long int recursiveMethod(const int num) {
    if (num == 1 || num == 2) {
        return 1;
    }
    return recursiveMethod(num - 1) + recursiveMethod(num - 2);
}

//пусть более 0.2 сек это заметно медленное ожидание ответа программы
int main(void) {
    int numberOfFibonacci = 60;
    for (int i = 1; i <= numberOfFibonacci; ++i) {

        double timeOfStartingRecursiveMethod = clock();
        long long int process1 = recursiveMethod(i);
        double timeOfEndingRecursiveMethod = clock();

        double timeOfStartingIterativeMethod = clock();
        long long int process2 = iterativeMethod(i);
        double timeOfEndingIterativeMethod = clock();

        double timeRecursive = ((double)(timeOfEndingRecursiveMethod - timeOfStartingRecursiveMethod))/CLOCKS_PER_SEC;
        double timeIterative = ((double)(timeOfEndingIterativeMethod - timeOfStartingIterativeMethod))/CLOCKS_PER_SEC;

        if (timeRecursive - timeIterative > 0.2) {
            printf("On number %d, the recursive program runs noticeably slower by about %f sec", i,
                   timeRecursive - timeIterative);
            return 0;
        }
    }
}
