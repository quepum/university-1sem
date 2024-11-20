#include <stdio.h>
#include <assert.h>
#include "tree.h"

int main() {
    //tests
    FILE *file = fopen("inputData.txt", "r");
    assert(file != NULL && "No such file\n");
    char buffer[100];
    fscanf(file, "%[^\n]", buffer);

    Tree *tree = buildTree(buffer);


    fclose(file);
    return 0;
}