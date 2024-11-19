#include <stdio.h>
#include <malloc.h>
#include <assert.h>
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
    Dictionary* dictionary = createDictionary();
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

            case 2:
                printf("Enter a key\n");
                scanf("%d", &key);
            case 3:
                printf("Enter a key\n");
                scanf("%d", &key);
                
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