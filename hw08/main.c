#include <stdio.h>
#include <string.h>

void showCommands() {
    printf("MENU:\n");
    printf("1. Add or Update value\n");
    printf("2. Get value by key\n");
    printf("3. Check if key exists\n");
    printf("4. Delete key\n");
    printf("5. Exit\n");
}

int main() {
    int command = 0;
    char key[256] = {'\0'};
    char value[256] = {'\0'};
    while (1) {
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
                break;
            case 2:
                printf("Enter key: ");
                fgets(key, 256, stdin);
                key[strcspn(key, "\n")] = 0;

                break;
            case 3:
                printf("Enter key: ");
                fgets(key, 256, stdin);
                key[strcspn(key, "\n")] = 0;

                break;
            case 4:
                printf("Enter key: ");
                fgets(key, 256, stdin);
                key[strcspn(key, "\n")] = 0;
                break;
            case 5:
                return 0;
            default:
                printf("Invalid option. Please, try again.\n");
        }
    }
}