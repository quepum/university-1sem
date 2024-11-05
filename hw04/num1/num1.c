#include <stdio.h>
#include "locale.h"
#include "tests.h"
#define SIZE (sizeof(int) * 8)
//const int SIZE = sizeof(int) * 8;

void fromDecimalToBinary(int num, int array[]) {
    for (int i = SIZE - 1; i >= 0; i--) {
        array[i] = ((num & 1) ? 1 : 0);
        num >>= 1;
    }
}

int fromBinaryToDecimal(const int binNum[]) {
    int currentExponent = 1;
    int result = 0;
    for (int i = SIZE - 1; i >= 0; i--) {
        result += binNum[i] * currentExponent;
        currentExponent <<= 1;
    }
    return result;
}

void printer(int array[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
}

void addition(int const number1[], int const number2[], int result[]) {
    int carry = 0;
    for (int i = SIZE - 1; i >= 0; i--) {
        int interResult = number1[i] + number2[i] + carry;
        result[i] = number1[i] ^ number2[i] ^ carry;
        carry = (interResult > 1) ? 1 : 0;
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    if (!(testsAddition() && testsDecimalToBinary() && testBinaryToDecimal())) {
        printf("Тесты не пройдены, что-то пошло не так");
        return 1;
    }
    printf("%s", "Тесты пройдены успешно\n");

    int number1 = 0;
    int number2 = 0;
    printf("%s", "Введите 2 числа\n");
    scanf("%d%d", &number1, &number2);

    int binNumber1[SIZE] = {0};
    int binNumber2[SIZE] = {0};
    int result[SIZE] = {0};

    fromDecimalToBinary(number1, binNumber1);
    fromDecimalToBinary(number2, binNumber2);

    printf("Число %d в двоичном представлении:\n", number1);
    printer(binNumber1);
    printf("Число %d в двоичном представлении:\n", number2);
    printer(binNumber2);
    addition(binNumber1, binNumber2, result);
    printf("Сумма чисел в двоичном представлении:\n");
    printer(result);

    number1 = fromBinaryToDecimal(binNumber1);
    number2 = fromBinaryToDecimal(binNumber2);

    printf("(%d) + (%d) = %d", number1, number2, fromBinaryToDecimal(result));
    return 0;
}
