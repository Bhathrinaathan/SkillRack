#include<stdio.h>
#include<stdlib.h>
int formedByS2(int i,char S1[],char S2[])
{
    int len1=strlen(S1),len2=strlen(S2),index=0;
    while(i<len1)
    {
        index=0;
        while(S1[i]==S2[index] && index<len2 && i<len1)
        {   i++;index++;    }
        if (i==len1)
            return 1;
        if (index<len2)
            return 0;
    }
    return 1;
}
int main()
{
    char S1[102],S2[102];
    scanf("%s\n%s",S1,S2);
    int index=0,i=0,flag=0,start=0;
    int len1=strlen(S1),len2=strlen(S2),flag2=0;
    if (S1[len1-3]==S2[0]&&S1[len1-2]==S2[1]&&S1[len1-1]==S2[2])
    {   printf("YES");return;    }
    while (i<len1)
    {
        index=0;start=i;
        while(S1[i]==S2[index] && index<len2 && i<len1)
        {    index++;i++;   }
        if (index==len2 || i==len1)
        {   flag=1;break;}
        i++;
    }
    if (flag==0)
    {   printf("NO");return; }
    int k=len2-1,j=start-1;
    while(j>=0)
    {
        if(S1[j]!=S2[k])
        {   printf("NO");return;    }
        j--;k--;
        if (k<0)
            k=len2-1;
    }
    if (formedByS2(start,S1,S2))
        printf("YES");
    else
        printf("NO");
}
