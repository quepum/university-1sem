#pragma once

#include <stdbool.h>
#include "list.h"

#define MAX_ROADS 1000
#define MAX_CITIES 1000

typedef struct Road Road;
typedef struct City City;
typedef struct State State;

// function for reading data from a file
bool readInputData(const char *filename, int *numCities, int *numRoads, Road *roads, int *numStates, int capitals[],
                   int *numCapitals, int *errorCode);


// function for finding the min distance from a city to any city in the state
int searchMinDistanceToState(int cityId, int stateId, State *states, Road *roads, int numRoads);

// function for initializing cities
void initializeCities(City *cities, int numCities);

// function for initializing states
void initializeStates(State *states, int numStates, int *capitals, City *cities, int *errorCode);

// function of distributing cities by state
void assignCitiesToStates(State *states, int numStates, City *cities, Road *roads, int numRoads, int numCities,
                          int *errorCode);

// the output function of the results
void printResults(State *states, int numStates);

// function that creates roads
Road *createRoads();

// function that creates cities
City *createCities();

// function that creates states
State *createStates(int numCapitals);

// function that deletes lists of cities from states
void freeStates(State *states, int numStates);