#include<stdio.h>
#include<stdlib.h>

int main()
{
    char S[100];
    scanf("%s",S);
    int freq[26]={0};
    for (int i=0;S[i]!='\0';i++)
        freq[S[i]-'a']++;
    for (int i=0;i<26;i++)
    {
        if (freq[i]>=1)
        {
            printf("%c:",i+'a');
            while (freq[++i]>=1);
            printf("%c\n",i-1+'a');
        }
    }
}
