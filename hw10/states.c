#include "states.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INFINITY 1000000

typedef struct Road {
    int from;
    int to;
    int len;
} Road;

typedef struct City {
    int id;
    int state;
} City;

typedef struct State {
    int id;
    List *cities;
} State;

Road *createRoads() {
    return calloc(MAX_ROADS, sizeof(Road));
}

City *createCities() {
    return calloc(MAX_CITIES, sizeof(City));
}

State *createStates(int numCapitals) {
    return calloc(numCapitals, sizeof(State));
}

bool readInputData(const char *filename, int *numCities, int *numRoads, Road *roads, int *numStates, int capitals[],
                   int *numCapitals, int *errorCode) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        *errorCode = -1;
        return false;
    }

    fscanf(file, "%d %d", numCities, numRoads);
    for (int i = 0; i < *numRoads; i++) {
        fscanf(file, "%d %d %d", &roads[i].from, &roads[i].to, &roads[i].len);
    }

    fscanf(file, "%d", numStates);
    for (int i = 0; i < *numStates; i++) {
        fscanf(file, "%d", &capitals[i]);
    }

    fclose(file);
    *numCapitals = *numStates;
    return true;
}

int searchMinDistanceToState(int cityId, int stateId, State *states, Road *roads, int numRoads) {
    int minDistance = INFINITY;
    List *cityList = states[stateId].cities;
    if (cityList == NULL) {
        return minDistance;
    }
    ListNode *current = getHead(cityList);
    while (current != NULL) {
        int stateCityId = *(int *) getData(current);
        for (int j = 0; j < numRoads; j++) {
            if ((roads[j].from == cityId && roads[j].to == stateCityId) ||
                (roads[j].to == cityId && roads[j].from == stateCityId)) {
                if (roads[j].len < minDistance) {
                    minDistance = roads[j].len;
                }
            }
        }
        current = getNextNode(current);
    }
    return minDistance;
}

void initializeCities(City *cities, int numCities) {
    for (int i = 0; i < numCities; i++) {
        cities[i].id = i;
        cities[i].state = 0;
    }
}

void initializeStates(State *states, int numStates, int *capitals, City *cities, int *errorCode) {
    for (int i = 0; i < numStates; i++) {
        states[i].id = i + 1;
        states[i].cities = createNewList(errorCode);
        int *capitalId = calloc(1, sizeof(int));
        if (capitalId == NULL) {
            *errorCode = -1;
            return;
        }
        *capitalId = capitals[i];
        addElement(states[i].cities, capitalId, errorCode);
        if (*errorCode == -1) {
            return;
        }
        cities[capitals[i]].state = states[i].id;
    }
}

void assignCitiesToStates(State *states, int numStates, City *cities, Road *roads, int numRoads, int numCities,
                          int *errorCode) {
    int assignedCities = numStates;
    while (assignedCities < numCities) {
        for (int i = 1; i <= numStates; i++) {
            int minDistance = INFINITY;
            int closestCityId = -1;

            for (int j = 0; j < numCities; j++) {
                if (cities[j].state == 0) {
                    int dist = searchMinDistanceToState(cities[j].id, i - 1, states, roads, numRoads);
                    if (dist < minDistance) {
                        minDistance = dist;
                        closestCityId = cities[j].id;
                    }
                }
            }
            if (closestCityId != -1) {
                int *cityId = calloc(1, sizeof(int));
                if (cityId == NULL) {
                    *errorCode = -1;
                    return;
                }
                *cityId = closestCityId;
                addElement(states[i - 1].cities, cityId, errorCode);
                if (*errorCode == -1) {
                    free(cityId);
                    return;
                }
                cities[closestCityId].state = states[i - 1].id;
                assignedCities++;
                if (assignedCities == numCities) {
                    break;
                }
            }
        }
    }
}

void printResults(State *states, int numStates) {
    for (int i = 0; i < numStates; i++) {
        printf("State %d: ", states[i].id);
        List *cityList = states[i].cities;
        ListNode *current = getHead(cityList);
        while (current != NULL) {
            int cityId = *(int *) getData(current);
            printf("%d ", cityId);
            current = getNextNode(current);
        }
        printf("\n");
    }
}

void freeStates(State *states, int numStates) {
    for (int i = 0; i < numStates; i++) {
        if (states[i].cities != NULL) {
            removeList(states[i].cities);
        }
    }
}