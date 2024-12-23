#include <stdio.h>
#include "list.h"
#include "tests.h"

int main() {
    if (!runAllTests()) {
        printf("Tests failed");
        return -1;
    }
    printf("Tests were passed successfully\n");

    int errorCode = 0;

    List* list = createNewList(&errorCode);
    if (errorCode == -1) {
        printf("Out of memory");
        return -1;
    }

    int elements[] = {5, 4, 3, 2, 1};
    int size = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < size; ++i) {
        addNewElement(list, elements[i], &errorCode);
        if (errorCode == -1){
            printf("Out of memory");
            deleteList(list);
            return -1;
        }
    }

    printf("Your list: ");
    printContent(list);

    deleteOddIndexes(list);

    printf("Your list after deleting elements with odd indexes: ");
    printContent(list);

    deleteList(list);
    return 0;
}