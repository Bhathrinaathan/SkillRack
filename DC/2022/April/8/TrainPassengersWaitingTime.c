#include<stdio.h>
#include<stdlib.h>
int waitingTime(int h,int m,int aH,int aM)
{
    int min=(aM-m);
    min+=(aH-h)*60;
    return min;
}
int main()
{
    int aH,aM,N,h,m;
    scanf("%d:%d\n%d",&aH,&aM,&N);
    char S[16];
    int waiting;
    for (int i=0;i<N;i++)
    {
        scanf("%s %d:%d",S,&h,&m);
        if ( (h==aH && m>=aM) || (h>aH))
            waiting=-1;
        else
            waiting=waitingTime(h,m,aH,aM);
        printf("%s %d\n",S,waiting);
    }
}
