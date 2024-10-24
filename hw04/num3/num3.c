#include <stdio.h>
#include <string.h>

#define SIZE 100


typedef struct Entry {
    char name[SIZE];
    char number[SIZE];
} Entry;

//чтение записей
int readEntries(const char* fileName, Entry collection[]){
    FILE *file;
    int numLines = 0;
    file = fopen("C:\\CLionProjects\\RepoGit1\\hw04\\num3\\dataBase.txt", "r");
    char name[SIZE];
    char phoneNumber[SIZE];
    while(fscanf(file, "%s", name) != EOF && fscanf(file, "%s", phoneNumber) != EOF) {
        strcpy(collection[numLines].name, name);
        strcpy(collection[numLines].number, phoneNumber);
        ++numLines;
    }
    fclose(file);
    return numLines;
}

// функция добавить запись
void addEntry(){
}
//распечатать все записи
void displayContent(int numLines, Entry collection[]){
    printf("Содержание телефонного справочника\n");
    for (int i = 0; i < numLines; ++i){
        printf("%s %s\n", collection[i].name, collection[i].number);
    }
    printf("Конец\n");
}
//найти телефон по имени
void searchTelephoneByName(const char name[], int numLines, Entry collection[]){
    for (int i = 0; i < numLines; ++i){
        if (strcmp(collection[i].name, name) == 0){
            printf("%s\n", collection[i].number);
        }
    }
    printf("Такого имени нет в справочнике\n");

}
//найти имя по телефону
void searchNameByTelephone(){

}
//сохранить файл
void save(){

}

void printCommands(){
    printf("ТЕЛЕФОННЫЙ СПРАВОЧНИК\n");
    printf("0 - выйти\n"
           "1 - добавить запись (имя и телефон)\n"
           "2 - распечатать все имеющиеся записи\n"
           "3 - найти телефон по имени\n"
           "4 - найти имя по телефону\n"
           "5 - сохранить текущие данные в файл\n");
    printf("Введите номер команды\n");
}

int main(void){
    int command = 0;
    printCommands();
    Entry collection[SIZE];
    int numberOfLines = readEntries("dataBase.txt", collection);
    do{
        scanf("%d", &command);
        switch (command) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                displayContent(numberOfLines, collection);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                printf("Такой команды не существует, введите номер снова\n");
        }
    } while (command !=0);

    return 0;
}