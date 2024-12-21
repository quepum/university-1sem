#include <stdio.h>
#include "list.h"
#include "tests.h"

#define SIZE 100

void readEntries(Record **head, const char *fileName, int *errorCode) {
    FILE *file;
    file = fopen(fileName, "a+");
    if (file == NULL) {
        *errorCode = -1;
        return;
    }
    char name[SIZE];
    char phoneNumber[SIZE];
    while (fscanf(file, "%s", name) != EOF && fscanf(file, "%s", phoneNumber) != EOF) {
        appendRecord(head, name, phoneNumber, errorCode);
        if (*errorCode == -1) {
            fclose(file);
            return;
        }
    }
    fclose(file);
}

int main(void) {
    if (!runTests()) {
        printf("Tests failed");
        return -1;
    }
    printf("Tests were passed successfully\n");

    int errorCode = 0;
    Record *head = NULL;
    int sortByName = 0;
    printf("Sort by name (1) or by phone number(0)?\n");
    scanf("%d", &sortByName);
    readEntries(&head, "hw06\\num3\\inputData.txt", &errorCode);
    if (errorCode == -1) {
        printf("Error: file doesn't exist");
        return -1;
    }
    head = mergeSort(head, sortByName);
    printf("Your sorted list is\n");
    printList(head);

    removeList(head);
    return 0;
}