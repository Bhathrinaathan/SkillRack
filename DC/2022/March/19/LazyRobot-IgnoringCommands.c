#include<stdio.h>
#include<stdlib.h>

int main()
{
    int N,ingnored=0,t=1,TG,X,curr=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d %d",&TG,&X);
        if (t<=TG)
        {
            t+=abs(curr-X);
            curr=X;
        }
        else
            ingnored++;
    }
    printf("%d\n%d",ingnored,curr);
}
