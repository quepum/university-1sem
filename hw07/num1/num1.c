#include <stdio.h>
#include <malloc.h>
#include "tree.h"

void showCommands() {
    printf("Dictionary commands:\n"
           "0-exit\n"
           "1-add value\n"
           "2-get value\n"
           "3-check key\n"
           "4-remove key and its value\n");
}

int main(void) {
    //tests

    int command = 0;
    int key = 0;
    Dictionary *dictionary = createDictionary();
    do {
        showCommands();
        scanf("%d", &command);
        switch (command) {
            case 0:
                break;
            case 1: //done
                printf("Enter a key\n");
                scanf("%d", &key);
                printf("Enter a value you want to add\n");
                char *value = malloc(sizeof(char) * 256);
                if (value == NULL){
                    printf("Error\n");
                    return -1;
                }
                scanf("%s", value);
                insert(dictionary, key, value);
            case 2: //done
                printf("Enter a key\n");
                scanf("%d", &key);
                printf("Key %d has value %s\n", key, findValueByKey(dictionary, key));
            case 3: //done
                printf("Enter a key\n");
                scanf("%d", &key);
                if (checkTheExistenceOfTheKey(dictionary, key)) {
                    printf("The key %d is in the dictionary\n", key);
                } else {
                    printf("There's no such key\n");
                }
            case 4:
                printf("Enter a key\n");
                scanf("%d", &key);


            default:
                printf("Invalid input, try again\n");
                break;
        }
    } while (command != 0);

    return 0;
}