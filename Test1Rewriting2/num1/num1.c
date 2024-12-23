#include <stdio.h>

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


int main() {
    int numbers[] = {123, 45, 678, 90, 876, 12, 999, 1, -234};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int maxSum = countMaxSum(numbers, size);

    printf("The numbers with the largest sum of digits (%d):\n", maxSum);

    for (int i = 0; i < size; i++) {
        if (sumOfDigits(numbers[i]) == maxSum) {
            printf("%d ", numbers[i]);
        }
    }
    return 0;
}