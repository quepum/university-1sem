#include <stdio.h>
#include "list.h"
#include "tests.h"

void showCommands() {
    printf("0 - exit\n"
           "1 - add a value to the sorted list\n"
           "2 - remove a value from the list\n"
           "3 - print the list\n");
}

int main(void) {
    if (!allTests()){
        printf("Tests failed, something went wrong");
        return -1;
    }
    printf("The tests were passed successfully\n");
    List *list = createList();
    int command = 0;
    do {
        showCommands();
        scanf("%d", &command);
        switch (command) {
            case 0:
                return 0;
            case 1: {
                int value = 0;
                printf("Enter a value to add:\n");
                scanf("%d", &value);
                orderInsert(list, value);
                printf("Successfully!\n");
                break;
            }
            case 2: {
                int value = 0;
                printf("Enter a value to remove:\n");
                scanf("%d", &value);
                int position = findPositionElement(list, value);
                if (position >= 0){
                    deleteElement(list, position);
                    printf("Successfully!\n");
                } else{
                    printf("No such element\n");
                }
                break;
            }
            case 3:
                printf("Your list is:\n");
                printList(list);
                break;
            default:
                printf("No such command\n");
                break;
        }
    } while (command < 4 && command > 0);
    return 0;
}