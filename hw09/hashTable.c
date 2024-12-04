#include <stdio.h>
#include <malloc.h>
#include "list.h"
#include "hashTable.h"

typedef struct HashTable {
    int size;
    float fillFactor;
    List **buckets;
} HashTable;

HashTable *createTable(int size) {
    HashTable *newTable = malloc(sizeof(HashTable));
    newTable->buckets = malloc(sizeof(Node *) * size);
    newTable->size = size;
    for (int i = 0; i < size; i++) {
        newTable->buckets[i] = NULL;
    }
    return newTable;
}

void freeTable(HashTable *hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        Node *current = (Node *) hashTable->buckets[i];
        while (current) {
            Node *temp = current;
            current = current->next;
            free(temp->word);
            free(temp);
        }
    }
    free(hashTable->buckets);
    free(hashTable);
}

float getLoadFactor(HashTable* hashTable) {
    return hashTable->fillFactor;
}