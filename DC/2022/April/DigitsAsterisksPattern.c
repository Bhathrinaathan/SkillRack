#include<stdio.h>
#include<stdlib.h>

int main()
{
    char S[101],output[10],max=0;
    int occur[10]={0},outIndex=0;
    scanf("%s",S);
    for (int i=0;i<strlen(S);i++)
    {
        occur[S[i]-'0']++;
        if (occur[S[i]-'0']==1)
            output[outIndex++]=S[i];
        if (occur[S[i]-'0']>max)
            max=occur[S[i]-'0'];
    }
    for (int i=0;i<outIndex;i++)
    {
        for (int c=0;c<occur[output[i]-'0'];c++)
            printf("%c ",output[i]);
        for (int c=occur[output[i]-'0'];c<max;c++)
            printf("* ");
        printf("\n");
    }
    
    
}
