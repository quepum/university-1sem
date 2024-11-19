#pragma once

#include <stdbool.h>

typedef struct Node Node;
typedef struct Dictionary Dictionary;

Dictionary *createDictionary();

char *findValueByKey(Dictionary *dictionary, int key);

bool keySearcher(Node *root, int key);

bool checkTheExistenceOfTheKey(Dictionary *dictionary, const int key);