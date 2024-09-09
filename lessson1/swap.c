#include <stdio.h>

int main()
{
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    x += y;
    y = x - y;
    x -= y;
    printf("%d\t%d", x, y);

    return 0;
}
