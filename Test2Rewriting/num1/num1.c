#include <stdio.h>
#include <stdbool.h>
#include "list.h"

void toFile(FILE *outputFile, List *listLessA, List *listBetweenAB, List *listMoreB) {
    rewriteToFile(outputFile, listLessA);
    rewriteToFile(outputFile, listBetweenAB);
    rewriteToFile(outputFile, listMoreB);
}

bool fromFile(FILE *inputFile, FILE *outputFile, const int a, const int b) {
    int errorCode = 0;
    List *listLessA = createNewList(&errorCode);
    List *listBetweenAB = createNewList(&errorCode);
    List *listMoreB = createNewList(&errorCode);
    if (errorCode == -1) {
        return false;
    }
    while (!feof(inputFile)) {
        int newElement = 0;
        fscanf(inputFile, "%d", &newElement);
        if (newElement < a) {
            addNewElement(listLessA, newElement);
        } else if (newElement > b) {
            addNewElement(listMoreB, newElement);
        } else {
            addNewElement(listBetweenAB, newElement);
        }
    }
    toFile(outputFile, listLessA, listBetweenAB, listMoreB);
    removeList(listLessA);
    removeList(listBetweenAB);
    removeList(listMoreB);
    return true;
}

bool isCorrectAnswer(FILE *file, const int correctAnswer[], const int size) {
    int i = 0;
    while (i < size) {
        int element = 0;
        fscanf(file, "%d", &element);
        if (correctAnswer[i] != element) {
            return false;
        }
        ++i;
    }
    return true;
}

bool runTests() {
    FILE *fileF1 = fopen("Test2Rewriting\\num1\\tests\\outputData1Test.txt", "r");
    int correctAnswer1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    FILE *fileG1 = fopen("Test2Rewriting\\num1\\tests\\outputData1Test.txt", "w");
    fromFile(fileF1, fileG1, 3, 8);
    if (!isCorrectAnswer(fileG1, correctAnswer1, 10)) {
        fclose(fileF1);
        fclose(fileG1);
        return false;
    }
    fclose(fileF1);
    fclose(fileG1);

    /*FILE *fileF2 = fopen("Test2Rewriting\\num1\\tests\\inputData2Test.txt", "r");
    int correctAnswer2[] = {4, 3, 2, 1, 10, 9, 8, 7, 6, 5};
    FILE *fileG2 = fopen("Test2Rewriting\\num1\\tests\\outputData2Test.txt", "w");
    fromFile(fileF2, fileG1, 5, 10);
    if (!isCorrectAnswer(fileG2, correctAnswer2, 10)) {
        fclose(fileF1);
        fclose(fileF2);
        fclose(fileG1);
        fclose(fileG2);
        return false;
    }*/

    return true;
}

int main(void) {
    /*if (!runTests()) {
        printf("Tests failed");
        return -1;
    }
    printf("Tests were passed successfully\n");*/

    FILE *fileF = fopen("Test2Rewriting\\num1\\inputData.txt", "r");
    FILE *fileG = fopen("Test2Rewriting\\num1\\outputData.txt", "w");
    if (fileF == NULL || fileG == NULL) {
        printf("File does not exist");
        return -1;
    }
    int a = 20;
    int b = 30;

    if (!fromFile(fileF, fileG, a, b)){
        printf("Error");
        fclose(fileF);
        fclose(fileG);
        return -1;
    }

    fclose(fileF);
    fclose(fileG);
    return 0;
}