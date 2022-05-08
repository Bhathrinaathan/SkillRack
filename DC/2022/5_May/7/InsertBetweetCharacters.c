#include<stdio.h>
#include<stdlib.h>
int main()
{
    char S[1001],ch;
    scanf("%s\n%c",S,&ch);
    printf("%c",S[0]);
    for (int i=1;i<strlen(S);i++)
    {
        printf("%c%c",ch,S[i]);
    }
}
