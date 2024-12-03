#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "hashTable.h"


int main(void) {
    FILE* file = fopen("inputData.txt", "r");
    char buffer[256];
    while (!feof(file)) {
        fscanf(file, "%s", buffer);
        char* word = malloc(sizeof(char) * strlen(buffer));
        strcpy(word, buffer);
        }
    fclose(file);
    return 0;
}