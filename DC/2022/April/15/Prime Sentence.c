#include<stdio.h>
#include<stdlib.h>
int SentenceValues(char *str)
{
    int val=0,i=0;
    while(str[i]!='\0')
    {
        if (tolower(str[i])>='a' && tolower(str[i])<='z')
            val+=tolower(str[i])- 'a' + 1;
        else if (str[i]>='0' && str[i]<='9')
            val+=str[i]-'0';
        i++;
    }
    //printf("%s %d\n",str,val);
    return val;
}
int isPrime(int N)
{
    if (N==2)
        return 1;
    for (int i=2;i<=N/2;i++)
        if (N%i==0)
            return 0;
    return 1;
}
int main()
{
    char S[100][101];
    int index=0,sum=0;
    while (scanf("%s",S[index])>=1)
        index++;
    for (int i=0;i<index;i++)
        sum+=SentenceValues(S[i]);
    if (isPrime(sum))
    {
        printf("Prime");
        return;
    }
    for (int i=0;i<index && index>1;i++)
    {
        if (isPrime(sum - SentenceValues(S[i])))
        {
            printf("Almost Prime");
            return;
        }
    }
    printf("Composite");
}
