#include <stdio.h>
#include <stdlib.h>
int sameInReverse(char *S,int len,char *str)
{
    int i=0;
    for (int i=0,j=len-1;j>=0;i++,j--)
    {
        if (str[i]!=S[j])
            return 0;
    }
    return 1;
}
char* removeReversedWords(char *str1, char *str2)
{
    int len=strlen(str1),len2=strlen(str2);
    char S[1001];
    char *res=malloc(sizeof(char) * len);
    int index=0,start=0,resI=0;
    for (int i=0;i<len;i++)
    {
        index=0;
        S[0]='\0';
        while(str1[i]!=' ' && i<=len-1)
            S[index++]=str1[i++];
        S[index]='\0';
        if (!(strcmp(S,str2)==0 || sameInReverse(S,index,str2)))
        {
            for (int j=0;j<strlen(S);j++)
                res[resI++]=S[j];
            res[resI++]=' ';
        }
    }
    if (resI==0)
        res="-1";
    return res;
}
int main()
{
    char str1[1001], str2[1001];
    scanf("%[^\n\r]\n\r%s", str1, str2);
    char *result = removeReversedWords(str1, str2);
    if(result == NULL || result == str1 || result == str2)
    {
        printf("String is not formed\n");
    }
    if(result[0] == ' ' || result[0] == '\0')
    {
        printf("String is empty\n");
    }
    printf("%s", result);
    return 0;
}
