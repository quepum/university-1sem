#include <stdbool.h>
#include "tests.h"
#define SIZE (sizeof(int) * 8)

bool isRightAnswer(const int correctAnswer[], const int currentAnswer[]) {
    for (int i = 0; i < SIZE; ++i) {
        if (correctAnswer[i] != currentAnswer[i]) {
            return false;
        }
    }
    return true;
}

bool testsDecimalToBinary() {
    int test2 = -4;
    int result2[SIZE] = {};
    fromDecimalToBinary(test2, result2);
    int correctAnswer2[SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                1, 0, 0};
    if (!isRightAnswer(correctAnswer2, result2)) {
        return false;
    }

    int test3 = 245;
    int result3[SIZE] = {};
    fromDecimalToBinary(test3, result3);
    int correctAnswer3[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0,
                                1, 0, 1};
    if (!isRightAnswer(correctAnswer3, result3)) {
        return false;
    }
    return true;
}

bool testBinaryToDecimal() {
    int test1[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1};
    int result1 = fromBinaryToDecimal(test1);
    int correctAnswer1 = 245;
    if (result1 != correctAnswer1) {
        return false;
    }

    int test2[SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0};
    int result2 = fromBinaryToDecimal(test2);
    int correctAnswer2 = -4;
    if (result2 != correctAnswer2) {
        return false;
    }
    return true;
}

bool testsAddition() {
    int numberA1 = 5;
    int numberB1 = -5;
    int binNumberA1[SIZE] = {0};
    int binNumberB1[SIZE] = {0};
    int result1[SIZE] = {0};
    int correctAnswer1[SIZE] = {0};
    fromDecimalToBinary(numberA1, binNumberA1);
    fromDecimalToBinary(numberB1, binNumberB1);
    addition(binNumberA1, binNumberB1, result1);
    if (!isRightAnswer(correctAnswer1, result1)) {
        return false;
    }

    int numberA2 = 5;
    int numberB2 = 5;
    int binNumberA2[SIZE] = {0};
    int binNumberB2[SIZE] = {0};
    int result2[SIZE] = {0};
    int correctAnswer2[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                                0, 1, 0};
    fromDecimalToBinary(numberA2, binNumberA2);
    fromDecimalToBinary(numberB2, binNumberB2);
    addition(binNumberA2, binNumberB2, result2);
    if (!isRightAnswer(correctAnswer2, result2)) {
        return false;
    }

    int numberA3 = -5;
    int numberB3 = -5;
    int binNumberA3[SIZE] = {0};
    int binNumberB3[SIZE] = {0};
    int result3[SIZE] = {0};
    int correctAnswer3[SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                                1, 1, 0};
    fromDecimalToBinary(numberA3, binNumberA3);
    fromDecimalToBinary(numberB3, binNumberB3);
    addition(binNumberA3, binNumberB3, result3);
    if (!isRightAnswer(correctAnswer3, result3)) {
        return false;
    }
    return true;
}

