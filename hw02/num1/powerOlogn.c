#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int powerFast(const int num, int exponent) {
    exponent = abs(exponent);

    if (num == 0 && exponent == 0) {
        printf("%s", "Not defined");
        return 0;
    }
    if (!exponent) {
        return 1;
    }
    if (exponent % 2 != 0) {
        return powerFast(num, exponent - 1) * num;
    }
    else {
        int result = powerFast(num, exponent / 2);
        return result * result;
    }
}


bool test1() {
    int correctAnswer = 1;
    return powerFast(2, 0) == correctAnswer;
}

bool test2() {
    int correctAnswer = 2;
    return powerFast(2, 1) == correctAnswer;
}

bool test3() {
    int correctAnswer = 1024;
    return powerFast(2, 10) == correctAnswer;
}

bool test4() {
    float correctAnswer = 0.25;
    return ((1.0 / powerFast(2, -2)) - correctAnswer < 0.0001);
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
        printf("Answer is %.5f\n", 1.0 / powerFast(number, exponent));
    } else {
        printf("Answer is %d\n", powerFast(number, exponent));
    }
    return 0;
}
