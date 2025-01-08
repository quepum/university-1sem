#pragma once
#include <stdbool.h>
#include "list.h"

typedef struct HashTable HashTable;

// function that creates a new hash table
HashTable *createHashTable(int capacity, int *errorCode);

// function that deletes hash table
void deleteHashTable(HashTable *hashTable);

// function that adds a word to the hash table, increments count if exists
bool addOrIncrement(HashTable *hashTable, char *word, int *errorCode);

// function that shows all elements of hash table
void printHashTable(HashTable *hashTable);

// function that calculates the fill factor of the hash table
double getFillFactor(HashTable *hashTable);

// function that gets the maximum list length from the hash table
int getMaxListLength(HashTable *hashTable);

// function that calculates the average list length in the hash table
double getAverageListLength(HashTable *hashTable);