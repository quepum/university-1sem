#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool is_prime(const int n) {
    for (int divisor = 2; divisor < sqrt(n) + 1; ++divisor) {
        if (n % divisor == 0) {
            return false;
        }
    }
    return true;
}


int main(void) {
    int number = 0;
    printf("%s", "Введите число: ");
    scanf("%d", &number);
    if (number > 1) {
        printf("%s", "Простыми числами являются:\n");
        for (int i = 2; i <= number; ++i) {
            if (is_prime(i) == true) {
                printf("%d\t", i);
            }
        }
    }
    else {
        printf("%s", "error");
    }
    return 0;
}
