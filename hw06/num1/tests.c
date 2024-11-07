#include "list.h"
#include <stdbool.h>

bool insertTest() {
    List *test = createList();
    insert(test, 0, 5);
    insert(test, 1, 9);
    return (findPositionElement(test, 5) == 0 && findPositionElement(test, 9) == 1);
}

bool orderInsertTest() {
    List *test = createList();
    orderInsert(test, 100);
    orderInsert(test, 0);
    orderInsert(test, -50);
    return (findPositionElement(test, 100) == 2 && findPositionElement(test, -50) == 0 &&
            findPositionElement(test, 0) == 1);
}

bool deleteElementTest(){
    List *test = createList();
    insert(test, 0, 5);
    insert(test, 1, 10);
    insert(test, 2, 15);
    deleteElement(test, 1);
    return (findPositionElement(test, 10) == -1);
}

bool allTests(){
    return (deleteElementTest() && orderInsertTest() && insertTest());
}