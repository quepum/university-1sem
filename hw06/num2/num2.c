#include <stdio.h>
#include "list.h"

int main(void){
    //tests
    int n = 0;
    int m = 0;
    printf("Enter the number of warriors\n");
    scanf("%d", &n);
    printf("Enter the parameter m\n");
    scanf("%d", &m);
    printf("The initial position is %d", counting(makeCircle(n), m));
}