#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, cnt = 0, flag = 0;
    scanf("%d %d", &a, &b);
    if(a < 0 || b < 0)
    {
        flag = 1; 
        a = fabs(a); 
        b=fabs(b);
    }
    if (b != 0)
    {
        while (a >= b)
        {
            a -= b;
            cnt += 1;
        }
    } else {printf("error");}
    
    if (flag == 1) 
    {
        printf("%d", -cnt);
        
    } else {printf("%d", cnt);}
    return 0;
}
