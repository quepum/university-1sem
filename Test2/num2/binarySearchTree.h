#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//the structure of tree
typedef struct BinarySearchTree BinarySearchTree;

//function that inserts value with its key
void insert(BinarySearchTree *dictionary, int value);

//function that creates a search tree
BinarySearchTree *createTree();

//function that deletes the used search tree
void deleteTree(BinarySearchTree *dictionary);

//a function that sorts the passed array, builds a binary tree based on it and overwrites it in a symmetrical order
void inOrderSort(int array[], int length);