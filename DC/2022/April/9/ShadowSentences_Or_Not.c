#include<stdio.h>
#include<stdlib.h>
int commonCharacters(char *S1,char *S2)
{
    int len=strlen(S1);
    for (int i=0;i<strlen(S1);i++){
        for (int j=0;j<strlen(S2);j++)
            if (S1[i]==S2[j])
                return 1;
    }
    return 0;
}
int shadowSentences(int N,char S1[][80],char S2[][80])
{
    for (int i=0;i<N;i++)
    {
        if (strlen(S1[i])!=strlen(S2[i]))
            return 0;
        if (commonCharacters(S1[i],S2[i]))
            return 0;
    }
    return 1;
}
int main()
{
    char S1[1000][80],S2[1000][80],ch;
    int i1=0,i2=0;
    while(scanf("%s%c",S1[i1++],&ch)>=1 && ch==' ');
    while(scanf("%s%c",S2[i2++],&ch)>=1 && ch==' ');
    if (i1==i2 && shadowSentences(i1,S1,S2))
        printf("YES");
    else
        printf("NO");
}
