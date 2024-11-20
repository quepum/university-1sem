#include <stdio.h>
#include <assert.h>
#include "tree.h"

int main() {
    //tests
    FILE *file = fopen("C:\\CLionProjects\\homeworks\\hw07\\num2\\inputData.txt", "r");
    assert(file != NULL && "No such file\n");
    char expression[100] = {'\0'};
    fscanf(file, "%[^\n]", expression);
    printf("%s\n", expression);
    Tree *tree = buildParseTree(expression);
    printf("%d ", calculateExpression(tree));

    fclose(file);
    deleteParseTree(tree);
    return 0;
}