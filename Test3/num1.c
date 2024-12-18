#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE ((sizeof (char)) * 8)

int fromBinaryToDecimal(const char numberString[]) {
    int binNumber = atoi(numberString);
    int power = 1;
    int result = 0;

    while (binNumber) {
        int lastDigit = binNumber % 10;
        binNumber /= 10;
        result += power * lastDigit;
        power *= 2;
    }
    return result;
}

bool tests() {
    char string1[SIZE] = "101101";
    char correctAnswer1 = 45;
    if (correctAnswer1 != fromBinaryToDecimal(string1)) {
        return false;
    }

    char string2[SIZE] = "1111001";
    char correctAnswer2 = 121;
    if (correctAnswer2 != fromBinaryToDecimal(string2)) {
        return false;
    }

    char string3[SIZE] = "0";
    char correctAnswer3 = 0;
    if (correctAnswer3 != fromBinaryToDecimal(string3)) {
        return false;
    }
    return true;
}

int main(void) {
    if (!tests()) {
        return -1;
    }
    printf("Tests were passed successfully\n");
    char string[SIZE] = "1111";
    char *result = calloc(SIZE, sizeof(char));
    printf("%s in decimal form is %s", string, itoa(fromBinaryToDecimal(string), result, 10));
    free(result);
    return 0;
}