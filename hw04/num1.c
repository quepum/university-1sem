#include <stdio.h>
#define SIZE (sizeof(int) * 8)

int fromBinaryToDecimal(const int binNum[]) {
    int currentExponent = 1;
    int result = 0;
    for (int i = SIZE - 1; i >= 0; i--) {
        result += binNum[i] * currentExponent;

        currentExponent *= 2;
    }
    return result;
}

int main(){
    int number1 = 0;
    int number2 = 0;

    printf("%s", "¬ведите два числа:\n");
    scanf("%d%d", &number1, &number2);

    int binNumber1[SIZE] = { 0 };
    int binNumber2[SIZE] = { 0 };
    int result[SIZE] = { 0 };

    number1 = fromBinaryToDecimal(binNumber1);
    number2 = fromBinaryToDecimal(binNumber2);

    printf("%d\n", number1);
    printf("%d\n", number2);
    printf("%d\n", number1 + number2);
    return 0;
}
