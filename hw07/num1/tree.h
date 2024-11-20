#pragma once

#include <stdbool.h>

typedef struct Node Node;
typedef struct Dictionary Dictionary;

Dictionary *createDictionary();
void deleteDictionary(Dictionary *dictionary);

//function for adding a key and a value if there are no such key in the dictionary
void insert(Dictionary *dictionary, int key, char *value);

//function of getting the value by key
char *getValue(Dictionary *dictionary, int key);

//function of checking the existence of this key in the dictionary
bool isKeyInTheDictionary(Dictionary *dictionary, int key);

//function of removing a key and its value from the dictionary
void removeKey(Dictionary *dictionary, int key);

//key value change function
void changeData(Dictionary *dictionary, int key, char *newData);