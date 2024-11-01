#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 100000

void checkRepeating(const char string[], char answer[], int length){
    char currentSymbol = ' ';
    int indexString = 0;
    int indexAnswer = 0;

    while (indexString < length - 1){
        if (currentSymbol != string[indexString]){
            answer[indexAnswer] = string[indexString];
            currentSymbol = string[indexString];
            ++indexAnswer;
        }
        ++indexString;
    }
}

int main(void) {
    char str[SIZE] = {"\0"};
    int counter = 0;
    FILE* file = fopen("C:\\CLionProjects\\RepoGit1\\TestRewrite1\\text.txt", "r");
    printf("Reading file...\n");
    if (file == NULL){
        printf("file can't be opened \n");
        return -1;
    }
    printf("Answer is\n");
    while (!feof(file)) {
        str[counter] = (char)fgetc(file);
        ++counter;
    }
    char answer[SIZE] = {'\0'};
    checkRepeating(str, answer, counter);
    printf("%s", answer);
    fclose(file);

    return 0;
}