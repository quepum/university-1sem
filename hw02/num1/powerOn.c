#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int powerSlow(const int n, int exponent) {
    if (n == 0 && exponent == 0) {
        printf("%s", "Not defined");
        return 0;
    }

    int result = 1;
    exponent = abs(exponent);

    for (int i = 0; i < exponent; ++i) {
        result *= n;
    }
    return result;
}

bool test1() {
    int correctAnswer = 1;
    return powerSlow(2, 0) == correctAnswer;
}

bool test2() {
    int correctAnswer = 2;
    return powerSlow(2, 1) == correctAnswer;
}

bool test3() {
    int correctAnswer = 1024;
    return powerSlow(2, 10) == correctAnswer;
}

bool test4() {
    float correctAnswer = 0.25;
    return  ((1.0 / powerSlow(2, -2)) - correctAnswer < 0.0001);
}

int main(void) {
    if (!(test1() && test2() && test3() && test4())) {
        printf("Tests failed, something went wrong");
        return 1;
    }

    int number = 0, exponent = 0;

    printf("%s", "Enter the number and exponent:");
    scanf("%d %d", &number, &exponent);

    if (exponent < 0) {
        printf("Answer is %.5f\n", 1.0 / powerSlow(number, exponent));
    }
    else {
        printf("Answer is %d\n", powerSlow(number, exponent));
    }
    return 0;
}
