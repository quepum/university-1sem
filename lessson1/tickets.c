#include <stdio.h>
#include <math.h>

int main()
{
    int lst[28] = {0};
    int res;
    for(int i=0; i < 10; i += 1) 
    {
        for(int j=0; j < 10; j+=1)
        {
            for(int k=0; k < 10; k+=1)
            {
                lst[i+j+k] = lst[i+j+k] + 1;
            }
        }
    }
    
    for(int x; x < 28; x+=1)
    {
        res += pow(lst[x], 2);
    }
    printf("%d", res);
    return 0;
}
