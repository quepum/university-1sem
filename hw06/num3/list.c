#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include "list.h"

void printList(Record *node) {
    while (node != NULL) {
        printf("%s %s\n", node->name, node->phone);
        node = node->next;
    }
    printf("\n");
}

void appendRecord(Record **head, char *name, char *phone, int *errorCode) {
    Record *newRecord = calloc(1, sizeof(Record));
    if (newRecord == NULL) {
        *errorCode = -1;
        return;
    }
    strcpy(newRecord->name, name);
    strcpy(newRecord->phone, phone);
    newRecord->next = NULL;

    if (*head == NULL) {
        *head = newRecord;
    } else {
        Record *last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newRecord;
    }
}

void removeList(Record *head) {
    Record *current = head;
    while (current != NULL) {
        Record *next = current->next;
        free(current);
        current = next;
    }
}

Record *merge(Record *left, Record *right, int sortByName) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    Record *result = NULL;

    if (sortByName) {
        if (strcmp(left->name, right->name) <= 0) {
            result = left;
            result->next = merge(left->next, right, sortByName);
        } else {
            result = right;
            result->next = merge(left, right->next, sortByName);
        }
    } else {
        // Сортировка по номеру телефона
        if (strcmp(left->phone, right->phone) <= 0) {
            result = left;
            result->next = merge(left->next, right, sortByName);
        } else {
            result = right;
            result->next = merge(left, right->next, sortByName);
        }
    }

    return result;
}

void split(Record *source, Record **left, Record **right) {
    Record *slow;
    Record *fast;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *left = source;
    *right = slow->next;
    slow->next = NULL;
}

Record *mergeSort(Record *head, int sortByName) {
    if (head == NULL || head->next == NULL) {
        return head; // Если список пуст или содержит один элемент
    }

    Record *left;
    Record *right;

    split(head, &left, &right);

    left = mergeSort(left, sortByName);
    right = mergeSort(right, sortByName);

    return merge(left, right, sortByName);
}
