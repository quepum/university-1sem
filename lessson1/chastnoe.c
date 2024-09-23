#include <stdio.h>
#include <math.h>

int incompleteQuotientCounter(const int num1, const int num2) {
    int result = 0;
    int dividend = abs(num1);
    int divisor = abs(num2);

    while (dividend >= divisor) {
        dividend -= divisor;
        ++result;
    }

    if (dividend == 0) {
        if (num1 < 0 || num2 < 0) {
            return -result;
        }
        return result;
    }
    if (num1 >= 0 && num2 > 0) {
        return result;
    }
    if (num1 <= 0 && num2 < 0) {
        return (result + 1);
    }
    return -(result + 1);
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
