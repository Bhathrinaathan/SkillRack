#include<stdio.h>
#include<stdlib.h>
int isConsonants(char ch)
{
    ch=tolower(ch);
    if (ch!='a'&&ch!='e'&&ch!='i'&&ch!='o'&& ch!='u')
        return 1;
    return 0;
}
int main()
{
    char S[1001],first,temp;
    scanf("%s",S);
    int len=strlen(S),pos=0,i,flag=0;
    for (i=0;i<len;i++)
    {
        if (isConsonants(S[i]))
        {
            if (flag==0){first=S[i];flag=1;}
            pos=i+1;
            while(isConsonants(S[pos%len])==0)
                pos++;
            if (pos>=len)
                S[i]=first;
            else
                S[i]=S[pos%len];
        }
    }
    printf("%s",S);
}
