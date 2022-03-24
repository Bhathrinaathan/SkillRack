#include<stdio.h>
#include<stdlib.h>

int main()
{
    char S[1000];
    scanf("%s",S);
    int len=strlen(S),count=0,i=0;
    while (i<len)
    {
        if (S[i]==S[i+1])
        {
            S[i]='#';
            count++;
            i++;
        }
        else
            i+=2;
    }
    printf("%d",(len-count)%2==0?count:count + 1);
}
