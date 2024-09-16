#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int func(const char stringBigger[], const int lengthBiggerString, const char stringSmaller[],
         const int lengthSmallerString) {
    int result = 0;
    bool success = false;

    for (int i = 0; i <= (lengthBiggerString - lengthSmallerString); ++i) {
        success = true;
        for (int j = 0; j < lengthSmallerString; ++j) {
            if (stringBigger[i + j] != stringSmaller[j]) {
                success = false;
                break;
            }
        }
        if (success == true) {
            ++result;
        }
    }
    return result;
}

int main(void) {
    char s[101] = "", s1[101] = "";

    printf("Введите 1 строку (не более 100 символов)\n");
    fgets(s, 101, stdin);

    printf("Введите 2 строку (не более 100 символов)\n");
    fgets(s1, 101, stdin);

    int lenS = strlen(s), lenS1 = strlen(s1);

    printf("Количество вхождений S1 в S как подстроки составляет: %d", func(s, lenS - 1, s1, lenS1 - 1));
    return 0;
}
