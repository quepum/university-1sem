#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "tree.h"
#include "tests.h"

void showCommands() {
    printf("DICTIONARY COMMANDS:\n"
           "0-exit\n"
           "1-add value\n"
           "2-get value\n"
           "3-check key\n"
           "4-remove key and its value\n");
}

int main(void) {
    tests();
    printf("Tests were passed successfully!\n");
    int command = 0;
    int key = 0;
    Dictionary *dictionary = createDictionary();
    do {
        showCommands();
        scanf("%d", &command);
        switch (command) {
            case 0:
                break;
            case 1:
                printf("Enter a key\n");
                scanf("%d", &key);
                printf("Enter a value you want to add\n");
                char *value = malloc(sizeof(char) * 256);
                assert(value != NULL && "Memory error\n");
                scanf("%s", value);
                if (isKeyInTheDictionary(dictionary, key)) {
                    changeData(dictionary, key, value);
                } else {
                    insert(dictionary, key, value);
                }
                printf("Successfully!\n");
                break;
            case 2:
                printf("Enter a key\n");
                scanf("%d", &key);
                printf("Key %d has value %s\n", key, getValue(dictionary, key));
                break;
            case 3:
                printf("Enter a key\n");
                scanf("%d", &key);
                if (isKeyInTheDictionary(dictionary, key)) {
                    printf("The key %d is in the dictionary\n", key);
                } else {
                    printf("There's no such key\n");
                }
                break;
            case 4:
                printf("Enter a key\n");
                scanf("%d", &key);
                if (isKeyInTheDictionary(dictionary, key)) {
                    removeKey(dictionary, key);
                } else {
                    printf("There is no such key\n");
                }
                break;
            default:
                printf("Invalid input, try again\n");
                deleteDictionary(dictionary);
                break;
        }
    } while (command != 0);
    deleteDictionary(dictionary);
    return 0;
}