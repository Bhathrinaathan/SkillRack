#include<stdio.h>
#include<stdlib.h>

int main()
{
    char num[7];
    int D,N,cate1=0,cate2=0;
    scanf("%d ",&N);
    for (int i=0;i<N;i++)
    {
        scanf("%d%s",&D,num);
        if (atof(num)>0.5)
            cate1+=D;
        else    
            cate2+=D;
    }
    printf("%d %d",cate1,cate2);
}
