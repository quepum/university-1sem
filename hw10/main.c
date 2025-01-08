#include "states.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int numCities = 0;
    int numRoads = 0;
    int numStates = 0;
    int numCapitals = 0;
    int errorCode = 0;

    Road *roads = createRoads();
    if (roads == NULL) {
        printf("Memory error");
        return -1;
    }
    int *capitals = calloc(MAX_CITIES, sizeof(int));
    if (capitals == NULL) {
        free(roads);
        printf("Memory error\n");
        return -1;
    }

    if (!readInputData("..\\hw10\\inputData.txt", &numCities, &numRoads, roads, &numStates,
                       capitals, &numCapitals, &errorCode)) {
        printf("Error: no such file");
        free(roads);
        free(capitals);
        return -1;
    }

    City *cities = createCities();
    if (cities == NULL) {
        free(roads);
        free(capitals);
        printf("Memory error");
        return -1;
    }
    initializeCities(cities, numCities);

    State *states = createStates(numCapitals);
    if (states == NULL) {
        free(roads);
        free(capitals);
        free(cities);
        printf("Memory error");
        return -1;
    }
    initializeStates(states, numStates, capitals, cities, &errorCode);
    if (errorCode == -1) {
        free(roads);
        free(capitals);
        free(cities);
        free(states);
        return -1;
    }

    assignCitiesToStates(states, numStates, cities, roads, numRoads, numCities, &errorCode);
    if (errorCode == -1) {
        free(roads);
        free(capitals);
        free(cities);
        freeStates(states, numStates);
        free(states);
        return -1;
    }
    printResults(states, numStates);
    freeStates(states, numStates);
    free(states);
    free(cities);
    free(roads);
    free(capitals);
    return 0;
}