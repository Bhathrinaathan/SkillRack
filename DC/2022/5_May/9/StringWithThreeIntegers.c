#include<stdio.h>
#include<stdlib.h>
int usedA=0,usedB=0,usedC=0;
int formedByABC(char *S,char A,char *B,char *C,int i)
{
    if (C[0]==S[i]&&C[1]==S[i+1]&&C[2]==S[i+2])
    {
        usedC=1;
        return i+2;
    }
    if (B[0]==S[i] && B[1]==S[i+1])
    {
        usedB=1;
        return i+1;
    }
    if (A==S[i])
    {
        usedA=1;
        return i;
    }
    return -1;
}
int main()
{
    char A,D2;
    char S[100];
    scanf("%c %c",&A,&D2);
    scanf("%s",S);
    char B[3],C[4];
    int change=0,i=0;
    B[0]=A;B[1]=D2;B[2]='\0';
    C[0]=B[0];C[1]=B[1];C[2]=D2;C[3]='\0';
    while(i<strlen(S))
    {
        change=formedByABC(S,A,B,C,i);
        if (change!=-1)
            i=change ;
        else
        {   printf("No");return;}
        i++;
    }
        printf("Yes");
}
