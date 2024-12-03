#include <stdio.h>

#include "list.h"
#include "hashTable.h"

typedef struct HashTable {
    int size;
    float fillFactor;
    List **buckets;
} HashTable;

