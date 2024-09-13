#include <stdbool.h>
#include <stdio.h>

bool balance(const char stringForCheking[], const int lenString) {
    int counterBracket = 0;
    for (int i = 0; i < lenString - 1; ++i) {
        if (counterBracket < 0) {
            return false;
        }
        if (stringForCheking[i] == '(') {
            ++counterBracket;
        }
        if (stringForCheking[i] == ')') {
            --counterBracket;
        }
    }
    if (counterBracket != 0) {
        return false;
    }
    return true;
}

int main(void) {
    char string[21];
    printf("%s", "Введите строку для проверки длиной не более 20 символов: ");
    fgets(string, 21, stdin);
    if (balance(string, sizeof(string)) == true) {
        printf("%s", "ДА");
    } else {
        printf("%s", "НЕТ");
    }
    return 0;
}
