#include <stdio.h>
#include "tree.h"
#include "tests.h"

int main() {
    if (!runTests()) {
        printf("Tests failed");
        return -1;
    }
    printf("Tests were passed successfully\n");

    FILE *file = fopen("hw07\\num2\\inputData.txt", "r");
    if (file == NULL) {
        printf("No such file");
        return -1;
    }

    char expression[100] = {'\0'};
    fscanf(file, "%[^\n]", expression);
    printf("%s\n", expression);

    int errorCode = 0;
    Tree *tree = buildParseTree(expression, &errorCode);
    if (errorCode == -1) {
        printf("Memory error");
        return -1;
    }

    int result = calculateExpression(tree);
    if (errorCode == -1) {
        return -1;
    }

    printf("%d ", result);
    fclose(file);
    removeTree(tree);
    return 0;
}