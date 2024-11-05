#include <stdio.h>
#include <stdbool.h>
#define SIZE (sizeof(int) * 8)

void fromDecimalToBinary(int num, int array[]){
    int bit = 1;
    for (int i = SIZE - 1; i >= 0; i--) {
        array[i] = ((num & bit) ? 1 : 0);
        num >>= 1;
    }
}

int fromBinaryToDecimal(const int binNum[]) {
    int currentExponent = 1;
    int result = 0;
    for (int i = SIZE - 1; i >= 0; i--) {
        result += binNum[i] * currentExponent;
        currentExponent *= 2;
    }
    return result;
}

void printer(int array[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
}

void addition(int const number1[], int const number2[], int result[]){
    int toRemember = 0;
    for (int i = SIZE - 1; i >= 0; i--) {
        int interResult = number1[i] + number2[i] + toRemember;
        switch (interResult) {
            case 0:
                result[i] = 0;
                toRemember = 0;
                break;
            case 1:
                result[i] = 1;
                toRemember = 0;
                break;
            case 2:
                result[i] = 0;
                toRemember = 1;
                break;
            case 3:
                result[i] = 1;
                toRemember = 1;
                break;
            default:
                printf("Error\n");
        }
    }
}

bool isRightAnswer(const int correctAnswer[], const int currentAnswer[]){
    for (int i = 0; i < SIZE; ++i){
        if (correctAnswer[i] != currentAnswer[i]){
            return false;
        }
    }
    return true;
}

bool testsIsBinary(){
    int test2 = -4;
    int result2[SIZE] = {};
    fromDecimalToBinary(test2, result2);
    int correctAnswer2[SIZE] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0};
    if(!isRightAnswer(correctAnswer2, result2)){
        return false;
    }

    int test3 = 245;
    int result3[SIZE] = {};
    fromDecimalToBinary(test3, result3);
    int correctAnswer3[SIZE] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0, 1, 0, 1};
    if(!isRightAnswer(correctAnswer3, result3)){
        return false;
    }
    return true;
}

bool testsIsDecimal(){
    int test1[SIZE] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0, 1, 0, 1};
    int result1 = fromBinaryToDecimal(test1);
    int correctAnswer1 = 245;
    if(result1 != correctAnswer1){
        return false;
    }

    int test2[SIZE] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0};
    int result2 = fromBinaryToDecimal(test2);
    int correctAnswer2 = -4;
    if(result2 != correctAnswer2){
        return false;
    }
    return true;
}

bool testsAddition(){
    int numberA1 = 5;
    int numberB1 = -5;
    int binNumberA1[SIZE] = {0};
    int binNumberB1[SIZE] = {0};
    int result1[SIZE] = {0};
    int correctAnswer1[SIZE] = {0};
    fromDecimalToBinary(numberA1, binNumberA1);
    fromDecimalToBinary(numberB1, binNumberB1);
    addition(binNumberA1, binNumberB1, result1);
    if(!isRightAnswer(correctAnswer1, result1)){
        return false;
    }

    int numberA2 = 5;
    int numberB2 = 5;
    int binNumberA2[SIZE] = {0};
    int binNumberB2[SIZE] = {0};
    int result2[SIZE] = {0};
    int correctAnswer2[SIZE] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0};
    fromDecimalToBinary(numberA2, binNumberA2);
    fromDecimalToBinary(numberB2, binNumberB2);
    addition(binNumberA2, binNumberB2, result2);
    if(!isRightAnswer(correctAnswer2, result2)){
        return false;
    }

    int numberA3 = -5;
    int numberB3 = -5;
    int binNumberA3[SIZE] = {0};
    int binNumberB3[SIZE] = {0};
    int result3[SIZE] = {0};
    int correctAnswer3[SIZE] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0};
    fromDecimalToBinary(numberA3, binNumberA3);
    fromDecimalToBinary(numberB3, binNumberB3);
    addition(binNumberA3, binNumberB3, result3);
    if(!isRightAnswer(correctAnswer3, result3)){
        return false;
    }
    return true;
}

int main(){
    if (!(testsAddition() && testsIsBinary() && testsIsDecimal())){
        printf("Òåñòû íå ïðîéäåíû, ÷òî-òî ïîøëî íå òàê");
        return 1;
    } else {
        printf("%s", "Òåñòû ïðîéäåíû óñïåøíî\n");
    }

    int number1 = 0;
    int number2 = 0;
    scanf("%d%d", &number1, &number2);

    int binNumber1[SIZE] = { 0 };
    int binNumber2[SIZE] = { 0 };
    int result[SIZE] = { 0 };

    fromDecimalToBinary(number1, binNumber1);
    fromDecimalToBinary(number2, binNumber2);

    printf("×èñëî %d â äâîè÷íîì ïðåäñòàâëåíèè:\n", number1);
    printer(binNumber1);
    printf("×èñëî %d â äâîè÷íîì ïðåäñòàâëåíèè:\n", number2);
    printer(binNumber2);
    addition(binNumber1, binNumber2, result);
    printf("Ñóììà ÷èñåë â äâîè÷íîì ïðåäñòàâëåíèè:\n");
    printer(result);

    number1 = fromBinaryToDecimal(binNumber1);
    number2 = fromBinaryToDecimal(binNumber2);

    printf("(%d) + (%d) = %d", number1, number2, fromBinaryToDecimal(result));
    return 0;
}
