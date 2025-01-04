#include <stdio.h>
#include <string.h>
#include "tree.h"
#include "tests.h"

void showCommands() {
    printf("MENU:\n");
    printf("1. Add or update value\n");
    printf("2. Get value by key\n");
    printf("3. Check if key exists\n");
    printf("4. Delete key\n");
    printf("5. Exit\n");
}

int main() {
    if (!tests()) {
        printf("Tests failed, something went wrong");
        return -1;
    }
    printf("The tests were passed successfully!\n");

    Dictionary *root = NULL;
    int command = 0;
    char key[256] = {'\0'};
    char value[256] = {'\0'};
    int errorCode = 0;
    while (true) {
        showCommands();
        printf("Choose an option: ");
        scanf("%d", &command);
        getchar();
        switch (command) {
            case 1:
                printf("Enter key: ");
                fgets(key, 256, stdin);
                key[strcspn(key, "\n")] = 0;
                printf("Enter value: ");
                fgets(value, 256, stdin);
                value[strcspn(value, "\n")] = 0;
                root = insert(root, key, value, &errorCode);
                if (errorCode != 0) {
                    freeTree(root);
                    printf("Out of memory");
                }
                if (!isAVL(root)) {
                    printf("Not AVL-tree\n");
                }
                break;
            case 2:
                printf("Enter key: ");
                fgets(key, 256, stdin);
                key[strcspn(key, "\n")] = 0;
                const char *result = getValue(root, key);
                if (result) {
                    printf("This key has value: %s\n", result);
                } else {
                    printf("Key not found.\n");
                }
                break;
            case 3:
                printf("Enter key: ");
                fgets(key, 256, stdin);
                key[strcspn(key, "\n")] = 0;
                if (isKeyInTree(root, key)) {
                    printf("Key exists.\n");
                } else {
                    printf("Key does not exist.\n");
                }
                break;
            case 4:
                printf("Enter key to delete: ");
                fgets(key, 256, stdin);
                key[strcspn(key, "\n")] = 0;
                root = deleteNode(root, key);
                if (!isAVL(root)) {
                    printf("Not AVL-tree\n");
                }
                break;
            case 5:
                freeTree(root);
                return 0;
            default:
                printf("Invalid option. Please, try again.\n");
        }
    }
}