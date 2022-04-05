#include<stdio.h>
#include<stdlib.h>

int main()
{
    int X,Y,len,pos=0,count=0,flag=0;
    char S[101];
    scanf("%s",S);
    scanf("%d %d",&X,&Y);
    len=strlen(S);
    while(pos!=0 ||flag==0)
    {
        if (count%2==1)
            pos+=Y;
        else 
            pos+=X;
        pos=pos%len;
        flag=1;
        count++;
    }
    printf("%d",count);
}
