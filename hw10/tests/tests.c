#include <stdio.h>
#include "../list.h"
#include "../states.h"

bool test1() {
    int numCities = 0;
    int numRoads = 0;
    int numStates = 0;
    int numCapitals = 0;
    Road roads[MAX_ROADS] = {0};
    int capitals[MAX_CITIES] = {0};

    if (!readInputData("C:\\CLionProjects\\homeworks\\hw10\\tests\\inputTest1.txt", &numCities, &numRoads, roads,
                       &numStates,
                       capitals, &numCapitals)) {
        printf("Memory error");
        return -1;
    }

    City cities[MAX_CITIES] = {0};
    initializeCities(cities, numCities);

    State states[MAX_CITIES] = {0};
    initializeStates(states, numStates, capitals, cities);

    assignCitiesToStates(states, numStates, cities, roads, numRoads, numCities);

    for (int i = 0; i < numStates; i++) {
        removeList(states[i].cities);
    }

    return true;
}

bool test2() {
    return true;
}

bool runAllTests() {
    return test1() && test2();
}