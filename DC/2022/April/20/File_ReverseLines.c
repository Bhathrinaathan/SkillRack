#include<stdio.h>
#include<stdlib.h>

int main()
{
    char S[20],arr[100][100],ch;
    int N,index=0,tindex=0;
    scanf("%s\n%d",S,&N);
    FILE *fp;
    fp=fopen(S,"r");
    while(fscanf(fp,"%s",arr[index]))
    {
        index++;
        if (index==N)
            break;
    }
    for (int i=index-1;i>=0;i--)
        printf("%s\n",arr[i]);
    fclose(fp)
