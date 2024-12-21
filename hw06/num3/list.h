#pragma once

typedef struct Record {
    char name[100];
    char phone[100];
    struct Record *next;
} Record;

// function that implements the merge sorting
Record *mergeSort(Record *head, int sortByName);

// function that shows the contents of the list
void printList(Record *node);

// function that deletes list
void removeList(Record *head);

// function that adds a new entry to the list
void appendRecord(Record **head, char *name, char *phone, int *errorCode);