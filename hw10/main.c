#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>
#include "list.h"

void getDataForMatrix(FILE *file, const int numberOfRoads, int **matrix) {
    for (int i = 0; i < numberOfRoads; ++i) {
        int row = 0;
        int column = 0;
        int lengthOfRoad = 0;
        fscanf(file, "%d", &row);
        fscanf(file, "%d", &column);
        fscanf(file, "%d", &lengthOfRoad);
        matrix[row][column] = lengthOfRoad;
        matrix[column][row] = lengthOfRoad;
    }
}

void printMatrix(int** matrix, int cities) {
    printf(" ");
    for(int i = 0; i < cities; i++) {
        printf(" %d", i);
    }
    printf("\n");
    for (int i = 0; i < cities; i++) {
        printf("%d|", i);
        for (int j = 0; j < cities; j ++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    FILE *file = fopen("C:\\CLionProjects\\homeworks\\hw10\\inputData.txt", "r");
    int numberOfCities = 0;
    int numberOfRoads = 0;
    fscanf(file, "%d", &numberOfCities);
    fscanf(file, "%d", &numberOfRoads);

    int **adjacencyMatrix = calloc(numberOfCities, sizeof(int*));
    for (int i = 0; i < numberOfCities; i++) {
        adjacencyMatrix[i] = calloc(numberOfCities, sizeof(int*));
    }
    assert(adjacencyMatrix != NULL);
    getDataForMatrix(file, numberOfRoads, adjacencyMatrix);

    int capitalsAmount = 0;
    fscanf(file, "%d", &capitalsAmount);

    printMatrix(adjacencyMatrix, numberOfCities);
    free(adjacencyMatrix);
    return 0;
}
