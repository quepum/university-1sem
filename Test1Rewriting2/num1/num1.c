#include <stdio.h>
#include <stdbool.h>

int sumOfDigits(int num) {
    int sum = 0;
    if (num < 0) {
        num = -num;
    }
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int countMaxSum(int numbers[], const int size) {
    int maxSum = -100000000;
    for (int i = 0; i < size; i++) {
        int currentSum = sumOfDigits(numbers[i]);
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }
    return maxSum;
}

bool isRightAnswer(const int elements[], const int expectedAnswer[], const int size, const int maxSum) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        int sumCurrentElement = sumOfDigits(elements[i]);
        if (sumCurrentElement == maxSum) {
            if (elements[i] != expectedAnswer[counter]) {
                return false;
            }
            ++counter;
        }
    }
    return true;
}

bool testsCommonElements() {
    int elements[] = {99, 99, 99};
    int size = 3;
    int maxSum = countMaxSum(elements, size);
    int expectedAnswer[3] = {99, 99, 99};
    return isRightAnswer(elements, expectedAnswer, size, maxSum);
}

bool testsCommonSum() {
    int elements[] = {19, 28, 37, 46, 55, 64};
    int size = 6;
    int maxSum = countMaxSum(elements, size);
    int expectedAnswer[] = {19, 28, 37, 46, 55, 64};
    return isRightAnswer(elements, expectedAnswer, size, maxSum);
}

bool testsNoElements() {
    int elements[] = {};
    int size = 0;
    int maxSum = countMaxSum(elements, size);
    int expectedAnswer[] = {0};
    return isRightAnswer(elements, expectedAnswer, size, maxSum);
}

bool testsNormalData() {
    int elements[] = {34, 76, -12, 11, 53};
    int size = 5;
    int maxSum = countMaxSum(elements, size);
    int expectedAnswer[] = {76};
    return isRightAnswer(elements, expectedAnswer, size, maxSum);
}

bool runAllTests() {
    return testsNormalData() && testsNoElements() && testsCommonSum() && testsCommonElements();
}

int main() {
    if (!runAllTests()) {
        printf("Tests failed");
        return -1;
    }
    printf("Tests were passed successfully\n");

    int numbers[] = {123, 45, 678, 90, 876, 12, 999, 1, -234};
    int size = 9;
    int maxSum = countMaxSum(numbers, size);

    printf("The numbers with the largest sum of digits (%d):\n", maxSum);

    for (int i = 0; i < size; i++) {
        if (sumOfDigits(numbers[i]) == maxSum) {
            printf("%d ", numbers[i]);
        }
    }
    return 0;
}