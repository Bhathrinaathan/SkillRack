#include<stdio.h>
#include<stdlib.h>

int main()
{
    int N,melted=0,rod,prev;
    scanf("%d",&N);
    scanf("%d ",&prev);
    printf("%d ",prev);
    for (int i=1;i<N;i++)
    {
        scanf("%d ",&rod);
        melted+=(rod - (prev+1));
        printf("%d ",prev + 1);
        prev++;
    }
    while (melted- (prev+ 1)>=0)
    {
        printf("%d ",prev+ 1);
        melted-=prev+1;
        prev++;
    }
}
