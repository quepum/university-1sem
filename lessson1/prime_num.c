#include <stdio.h>

int main()
{
    int n, cnt;
    scanf("%d", &n);
    for(int i=1; i <= n; i+=1)
    {
        cnt = 0;
        for(int j = 1; j <= i; j += 1)
        {
            if (i % j == 0) {cnt += 1;}
        }
        if(cnt == 2 || i == 1) {printf("%d\t", i);}
    }
    
    return 0;
}
