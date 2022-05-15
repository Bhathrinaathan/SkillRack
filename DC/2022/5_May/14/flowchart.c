#include<stdio.h>
#include<stdlib.h>
int main()
{
    int N,X,Y,count=0;
    scanf("%d %d %d",&N,&X,&Y);
    int ctr=1;
    while(ctr1<X)
    { 
        int ctr2=1;
        while(ctr2<=Y)
        { 
            printf("%d %d",ctr1,ctr2);
            count++;
            if (count==N)
                return;
            ctr2++;
        }
        ctr1++;
    }
}
