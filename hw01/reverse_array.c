#include <stdio.h>

void reverse(int result[], const int indexStart, const int indexEnd) {
    int stop = 0, sequenceLength = indexEnd - indexStart + 1;

    if (sequenceLength % 2 == 0) {
        stop = indexStart + ((sequenceLength) / 2);
    } else {
        stop = indexStart + ((sequenceLength - 1) / 2);
    }

    for (int i = indexStart; i < stop; ++i) {
        int initialElement = result[i];
        result[i] = result[indexEnd - i];
        result[indexEnd - i] = initialElement;
    }
}

int main(void) {
    int m = 4, n = 5;
    int arrayOfNumbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    reverse(arrayOfNumbers, 0, m - 1);
    reverse(arrayOfNumbers, 0, n + m - 1);
    reverse(arrayOfNumbers, 0, n - 1);

    for (int i = 0; i <= (m + n - 1); ++i) {
        printf("%d\t", arrayOfNumbers[i]);
    }

    return 0;
}
