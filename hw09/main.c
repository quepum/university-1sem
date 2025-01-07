#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashTable.h"
#include "tests.h"

#define INITIAL_CAPACITY 50

int main(void) {
    if (!runAllTests()) {
        printf("Tests failed");
        return -1;
    }
    printf("Tests were passed successfully\n");

    FILE *file = fopen("..\\hw09\\inputData.txt", "r");
    if (file == NULL) {
        printf("No such file");
        return -1;
    }

    int errorCode = 0;
    HashTable *hashTable = createHashTable(INITIAL_CAPACITY, &errorCode);
    if (errorCode != 0) {
        printf("Error creating hash table");
        fclose(file);
        return -1;
    }

    char buffer[256] = {'\0'};
    while (fscanf(file, "%255s", buffer) == 1) {
        char *word = strdup(buffer);
        if (word == NULL) {
            printf("Memory allocation error");
            deleteHashTable(hashTable);
            fclose(file);
            return -1;
        }

        if (word[0] != '\0') {
            if (!addOrIncrement(hashTable, word, &errorCode)) {
                printf("Error adding/incrementing word");
                free(word);
                deleteHashTable(hashTable);
                fclose(file);
                return -1;
            }
        }
        free(word);
    }
    fclose(file);


    printf("Hash-table statistic\n");
    double loadFactor = getFillFactor(hashTable);
    printf("Load factor: %.2f\n", loadFactor);

    double averageListLength = getAverageListLength(hashTable);
    printf("Average list length: %.2f\n", averageListLength);

    int maxListLength = getMaxListLength(hashTable);
    printf("Max list length: %d\n", maxListLength);

    deleteHashTable(hashTable);
    return 0;
}