#include<stdio.h>
#include<stdlib.h>

int main()
{
    char S[1000];
    scanf("%s",S);
    int len=strlen(S),freq[26],curr;
    for (int i=0;i<26;i++){freq[i]=0;}
    for (int i=0;i<len;i++)
    {
        curr=S[i]-'a';
        if ( S[i]+freq[S[i]-'a'] > 'z')
            S[i]='a' + (S[i]+freq[S[i]-'a'] - 'a')%26 ;
        else
            S[i]+=freq[S[i]-'a'];
        freq[curr]++;
    }
    printf("%s",S);
}
