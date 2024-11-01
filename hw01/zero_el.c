#include <stdio.h>

int count_zero(const int size, const int numbers[]) {
    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if (numbers[i] == 0) {
            ++counter;
        }
    }
    return counter;
}

int main(void) {
    int list_of_numbers[10] = {8, 1, 9, 0, 4, 5, 0, 3, 0, 0};
    int len_list = sizeof(list_of_numbers) / sizeof(list_of_numbers[0]);
    printf("%d", count_zero(len_list, list_of_numbers));
    return 0;
}
