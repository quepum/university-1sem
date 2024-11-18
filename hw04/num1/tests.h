#pragma once
#include <stdbool.h>

//checking the correct answers for the tests
bool isRightAnswer(const int correctAnswer[], const int currentAnswer[]);

//test of converting a number to binary form
bool testsDecimalToBinary();

//test of converting a number to decimal form
bool testBinaryToDecimal();

//the test of adding numbers in binary form
bool testsAddition();

//converting numbers from decimal to binary
void fromDecimalToBinary(int num, int array[]);

//converting numbers from binary to decimal
int fromBinaryToDecimal(const int binNum[]);

//adding numbers in binary form
void addition(int const number1[], int const number2[], int result[]);


