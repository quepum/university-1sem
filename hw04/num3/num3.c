#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 100
#define TESTSIZE 5

typedef struct Entry {
    char name[SIZE];
    char number[SIZE];
} Entry;

//чтение записей
int readEntries(const char *fileName, Entry collection[]) {
    FILE *file;
    int numLines = 0;
    file = fopen(fileName, "a+");
    char name[SIZE];
    char phoneNumber[SIZE];
    while (fscanf(file, "%s", name) != EOF && fscanf(file, "%s", phoneNumber) != EOF) {
        strcpy(collection[numLines].name, name);
        strcpy(collection[numLines].number, phoneNumber);
        ++numLines;
    }
    fclose(file);
    return numLines;
}

// функция добавить запись
int addEntry(const char newName[], const char newPhoneNumber[], int *numLines, Entry collection[]) {
    if (*numLines < SIZE) {
        Entry newEntry = {{'\0'},
                          {'\0'}};
        strcpy(newEntry.name, newName);
        strcpy(newEntry.number, newPhoneNumber);
        collection[*numLines] = newEntry;
        ++(*numLines);
        return 0;
    }
    return -1;
}

//распечатать все записи
void displayContent(const int numLines, Entry collection[]) {
    printf("Содержание телефонного справочника\n");
    for (int i = 0; i < numLines; ++i) {
        printf("%s %s\n", collection[i].name, collection[i].number);
    }
    printf("Конец\n");
}

//найти телефон по имени
int searchTelephoneByName(const char name[], const int numLines, Entry collection[]) {
    for (int i = 0; i < numLines; ++i) {
        if (strcmp(collection[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

//найти имя по телефону
int searchNameByTelephone(const char phoneNumber[], const int numLines, Entry collection[]) {
    for (int i = 0; i < numLines; ++i) {
        if (strcmp(collection[i].number, phoneNumber) == 0) {
            return i;
        }
    }
    return -1;
}

//сохранить файл
void saveChanges(const char *fileName, const int numLines, Entry collection[]) {
    FILE *file;
    file = fopen(fileName, "w");
    for (int i = 0; i < numLines; ++i) {
        fprintf(file, "%s %s\n", collection[i].name, collection[i].number);
    }
    printf("Изменения успешно сохранены\n");
    fclose(file);
}

void printCommands(void) {
    printf("ТЕЛЕФОННЫЙ СПРАВОЧНИК\n");
    printf("0 - выйти\n"
           "1 - добавить запись (имя и телефон)\n"
           "2 - распечатать все имеющиеся записи\n"
           "3 - найти телефон по имени\n"
           "4 - найти имя по телефону\n"
           "5 - сохранить текущие данные в файл\n");
    printf("Введите номер команды\n");
}

bool testsOfSearchingByName() {
    Entry testingCollection1[TESTSIZE] = {{"Elena", "12345"},
                                          {"James", "098764"},
                                          {"Egor",  "234135"},
                                          {"Ann",   "234211"},
                                          {"Mary",  "2131314577"}};
    if (searchTelephoneByName("Mary", TESTSIZE, testingCollection1) == -1) {
        return false;
    }
    Entry testingCollection2[TESTSIZE] = {{"Elena", "12345"},
                                          {"James", "098764"},
                                          {"Egor",  "234135"},
                                          {"Ann",   "234211"},
                                          {"Mary",  "2131314577"}};
    if (searchTelephoneByName("Alina", TESTSIZE, testingCollection2) != -1) {
        return false;
    }

    Entry testingCollection3[TESTSIZE] = {};
    if (searchTelephoneByName("Mary", TESTSIZE, testingCollection3) != -1) {
        return false;
    }
    return true;
}

bool testsOfSearchingByTelephone() {
    Entry testingCollection1[TESTSIZE] = {{"Elena", "12345"},
                                          {"James", "098764"},
                                          {"Egor",  "234135"},
                                          {"Ann",   "234211"},
                                          {"Mary",  "2131314577"}};
    if (searchNameByTelephone("234211", TESTSIZE, testingCollection1) == -1) {
        return false;
    }
    Entry testingCollection2[TESTSIZE] = {{"Elena", "12345"},
                                          {"James", "098764"},
                                          {"Egor",  "234135"},
                                          {"Ann",   "234211"},
                                          {"Mary",  "2131314577"}};
    if (searchNameByTelephone("66666", TESTSIZE, testingCollection2) != -1) {
        return false;
    }
    Entry testingCollection3[TESTSIZE] = {};
    if (searchNameByTelephone("9898989898", TESTSIZE, testingCollection3) != -1) {
        return false;
    }
    return true;
}

bool testOfAddingEntry() {
    Entry testingCollection[TESTSIZE] = {};
    int numLines = 0;
    char newName[SIZE] = "Lexus";
    char newPhone[SIZE] = "77777";
    addEntry(newName, newPhone, &numLines, testingCollection);
    if (strcmp(testingCollection[0].name, newName) != 0 || strcmp(testingCollection[0].number, newPhone) != 0) {
        return false;
    }
    return true;
}

int main(void) {
    if (!(testsOfSearchingByName() && testsOfSearchingByTelephone() && testOfAddingEntry())) {
        printf("Тесты не пройдены, что-то пошло не так\n");
        return 1;
    } else {
        printf("%s", "Программа успешно прошла все тесты\n");
    }

    int command = 0;
    printCommands();
    Entry collection[SIZE];
    int numberOfLines = readEntries("dataBase.txt", collection);
    do {
        scanf("%d", &command);
        switch (command) {
            case 0:
                break;
            case 1:
                printf("Введите имя контакта для записи\n");
                char nameForAdding[SIZE] = {'\0'};
                scanf("%s", nameForAdding);
                printf("Введите номер телефона контакта %s для записи\n", nameForAdding);
                char numberForAdding[SIZE] = {'\0'};
                scanf("%s", numberForAdding);
                if (addEntry(nameForAdding, numberForAdding, &numberOfLines, collection) == 0) {
                    printf("Успешно, не забудьте сохранить изменения\n");
                } else {
                    printf("Место для записи кончилось, в справочнике может храниться не более 100 записей\n");
                }
                break;
            case 2:
                displayContent(numberOfLines, collection);
                break;
            case 3:
                printf("Введите имя контакта:\n");
                char name[SIZE] = {'\0'};
                scanf("%s", name);
                int resultOfSearchingByName = searchTelephoneByName(name, numberOfLines, collection);
                if (resultOfSearchingByName != -1) {
                    printf("%s\n", collection[resultOfSearchingByName].number);
                } else {
                    printf("Такого имени нет в телефонном справочнике\n");
                }
                break;
            case 4:
                printf("Введите номер телефона контакта:\n");
                char phoneNumber[SIZE] = {'\0'};
                scanf("%s", phoneNumber);
                int resultOfSearchingByPhone = searchNameByTelephone(phoneNumber, numberOfLines, collection);
                if (resultOfSearchingByPhone != -1) {
                    printf("%s\n", collection[resultOfSearchingByPhone].name);
                } else {
                    printf("Такого номера нет в телефонном справочнике\n");
                }
                break;
            case 5:
                saveChanges("dataBase.txt", numberOfLines, collection);
                break;
            default:
                printf("Команды с таким номером не существует\n");
        }
    } while (command <= 5 && command > 0);
    return 0;
}