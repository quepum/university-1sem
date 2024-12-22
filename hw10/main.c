#include "states.h"
#include "list.h"


int main(void) {
    int numCities = 0;
    int numRoads = 0;
    int numStates = 0;
    int numCapitals = 0;
    Road roads[MAX_ROADS] = {0};
    int capitals[MAX_CITIES] = {0};
    int errorCode = 0;

    /*
    State 1: 2 1 0
    State 2: 4 3
    */
    if (!readInputData("hw10\\inputData.txt", &numCities, &numRoads, roads, &numStates,
                       capitals, &numCapitals, &errorCode)) {
        return -1;
    }

    City cities[MAX_CITIES] = {0};
    initializeCities(cities, numCities);

    State states[MAX_CITIES] = {0};
    initializeStates(states, numStates, capitals, cities, &errorCode);
    if (errorCode == -1) {
        return -1;
    }

    assignCitiesToStates(states, numStates, cities, roads, numRoads, numCities, &errorCode);
    printResults(states, numStates);
    for (int i = 0; i < numStates; i++) {
        removeList(states[i].cities);
    }
    return 0;
}