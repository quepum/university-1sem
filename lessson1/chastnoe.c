#include <stdio.h>
#include <stdbool.h>

int incompleteQuotientCounter(int dividend, int divisor) {
    bool dividendIsNegative = false;
    bool divisorIsNegative = false;

    if (dividend < 0) {
        dividend = -dividend;
        dividendIsNegative = true;
    }
    if (divisor < 0) {
        divisor = -divisor;
        divisorIsNegative = true;
    }

    int initialDividend = dividend;

    int result = 0;
    while (initialDividend >= divisor) {
        initialDividend -= divisor;
        ++result;
    }

    if (dividendIsNegative != divisorIsNegative) {
        if (dividendIsNegative && !divisorIsNegative) {
            return -result - 1;
        } else {
            return -result;
        }
    }

    if (dividendIsNegative && divisorIsNegative) {
        return result + 1;
    } else {
        return result;
    }
}

int main(void) {
    int a = 0, b = 0;

    printf("Введите делимое и делитель\n");
    scanf("%d %d", &a, &b);

    if (b != 0) {
        printf("Неполное частное равно %d", incompleteQuotientCounter(a, b));
    }
    else {
        printf("%s", "error");
    }

    return 0;
}
