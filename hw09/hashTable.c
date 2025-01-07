#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "list.h"

typedef struct HashTable {
    List **buckets;
    int capacity;
    int size;
} HashTable;

unsigned int hash(const char *word, int capacity) {
    unsigned int hashValue = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        hashValue = hashValue * 31 + word[i];
    }
    return hashValue % capacity;
}

HashTable *createHashTable(int capacity, int *errorCode) {
    HashTable *hashTable = (HashTable *) calloc(1, sizeof(HashTable));
    if (hashTable == NULL) {
        *errorCode = 1;
        return NULL;
    }
    hashTable->buckets = (List **) calloc(capacity, sizeof(List *));
    if (hashTable->buckets == NULL) {
        free(hashTable);
        *errorCode = 1;
        return NULL;
    }
    hashTable->capacity = capacity;
    hashTable->size = 0;
    return hashTable;
}

void deleteHashTable(HashTable *hashTable) {
    if (hashTable == NULL) {
        return;
    }
    if (hashTable->buckets != NULL) {
        for (int i = 0; i < hashTable->capacity; i++) {
            deleteList(hashTable->buckets[i]);
        }
        free(hashTable->buckets);
    }
    free(hashTable);
}


bool addOrIncrement(HashTable *hashTable, char *word, int *errorCode) {
    if (!hashTable || !word) {
        *errorCode = 1;
        return false;
    }

    unsigned int hashValue = hash(word, hashTable->capacity);

    if (hashTable->buckets[hashValue] == NULL) {
        hashTable->buckets[hashValue] = createList();
        if (hashTable->buckets[hashValue] == NULL) {
            *errorCode = 1;
            return false;
        }
    }

    Node *existingNode = findElement(hashTable->buckets[hashValue], word);
    if (existingNode != NULL) {
        incrementCount(existingNode);
        return true;
    } else {
        if (!addNewElement(hashTable->buckets[hashValue], word)) {
            *errorCode = 1;
            return false;
        }
        hashTable->size++;
        return true;
    }
}

void printHashTable(HashTable *hashTable) {
    if (hashTable == NULL) {
        return;
    }
    for (int i = 0; i < hashTable->capacity; i++) {
        if (hashTable->buckets[i] != NULL) {
            printList(hashTable->buckets[i]);
        }
    }
}


double getFillFactor(HashTable *hashTable) {
    if (hashTable == NULL) {
        return 0.0;
    }
    return (double) hashTable->size / hashTable->capacity;
}

int getMaxListLength(HashTable *hashTable) {
    if (hashTable == NULL) {
        return 0;
    }
    int maxLength = 0;
    for (int i = 0; i < hashTable->capacity; i++) {
        if (hashTable->buckets[i] != NULL) {
            int listLength = getListLength(hashTable->buckets[i]);
            if (listLength > maxLength) {
                maxLength = listLength;
            }
        }
    }
    return maxLength;
}

double getAverageListLength(HashTable *hashTable) {
    if (hashTable == NULL) {
        return 0.0;
    }
    int totalLength = 0;
    int countNotEmptyLists = 0;
    for (int i = 0; i < hashTable->capacity; i++) {
        if (hashTable->buckets[i] != NULL) {
            int listLength = getListLength(hashTable->buckets[i]);
            if (listLength > 0) {
                totalLength += listLength;
                countNotEmptyLists++;
            }
        }
    }
    return (countNotEmptyLists > 0) ? (double) totalLength / countNotEmptyLists : 0.0;
}