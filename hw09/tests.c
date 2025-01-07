#include "hashTable.h"

bool testForCreatingHashTable() {
    int errorCode = 0;
    HashTable *hashTable = createHashTable(100, &errorCode);
    deleteHashTable(hashTable);
    return errorCode == 0;
}

bool testForAddingNewElement() {
    int errorCode = 0;
    HashTable *hashTable = createHashTable(100, &errorCode);
    addOrIncrement(hashTable, "word", &errorCode);
    deleteHashTable(hashTable);
    return errorCode == 0;
}

bool testForAddingCommonElements() {
    int errorCode = 0;
    HashTable *hashTable = createHashTable(100, &errorCode);
    addOrIncrement(hashTable, "word", &errorCode);
    addOrIncrement(hashTable, "word", &errorCode);
    deleteHashTable(hashTable);
    return errorCode == 0;
}

bool testForCountingFillFactor() {
    int errorCode = 0;
    HashTable *hashTable = createHashTable(100, &errorCode);
    addOrIncrement(hashTable, "word", &errorCode);
    double correctAnswer = 1.0 / 100.0;
    double answer = getFillFactor(hashTable);
    deleteHashTable(hashTable);
    return (answer - correctAnswer) < 1000000;
}

bool testForGetMaxListLength() {
    int errorCode = 0;
    HashTable *hashTable = createHashTable(100, &errorCode);
    addOrIncrement(hashTable, "word", &errorCode);
    int answer = getMaxListLength(hashTable);
    deleteHashTable(hashTable);
    return answer == 1;
}

bool testForGetAverageListLength() {
    int errorCode = 0;
    HashTable *hashTable = createHashTable(100, &errorCode);
    addOrIncrement(hashTable, "word", &errorCode);
    double answer = getAverageListLength(hashTable);
    deleteHashTable(hashTable);
    return answer == 1;
}

bool runAllTests() {
    return testForAddingCommonElements() && testForAddingNewElement() && testForCountingFillFactor() &&
           testForCreatingHashTable() && testForGetAverageListLength() && testForGetMaxListLength();
}

