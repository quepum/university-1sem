#include <stdbool.h>
#include "tree.h"

bool runTests() {
    int errorCode = 0;

    char testsExpression1[] = "(+ 3 5)";
    int correctAnswer1 = 8;
    Tree *testTree1 = buildParseTree(testsExpression1, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    if (correctAnswer1 != calculateExpression(testTree1)) {
        removeTree(testTree1);
        return false;
    }
    removeTree(testTree1);

    char testsExpression2[] = "(- 5 3)";
    int correctAnswer2 = -2;
    Tree *testTree2 = buildParseTree(testsExpression2, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    if (correctAnswer2 != calculateExpression(testTree2)) {
        removeTree(testTree2);
        return false;
    }
    removeTree(testTree2);

    char testsExpression3[] = "(/ 2 4)";
    int correctAnswer3 = 2;
    Tree *testTree3 = buildParseTree(testsExpression3, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    if (correctAnswer3 != calculateExpression(testTree3)) {
        removeTree(testTree3);
        return false;
    }
    removeTree(testTree3);

    char testsExpression4[] = "(* -3 -5)";
    int correctAnswer4 = 15;
    Tree *testTree4 = buildParseTree(testsExpression4, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    if (correctAnswer4 != calculateExpression(testTree4)) {
        removeTree(testTree4);
        return false;
    }
    removeTree(testTree4);

    char testsExpression5[] = "(- (+ 1 2) (* 3 4))";
    int correctAnswer5 = 9;
    Tree *testTree5 = buildParseTree(testsExpression5, &errorCode);
    if (errorCode == -1) {
        return false;
    }
    if (correctAnswer5 != calculateExpression(testTree5)) {
        removeTree(testTree5);
        return false;
    }
    removeTree(testTree5);

    return true;

}