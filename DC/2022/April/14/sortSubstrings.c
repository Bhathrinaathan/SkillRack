#include <stdio.h>
#include <stdlib.h>

typedef struct BoundedArray
{
    int SIZE;
    char **words;
} boundedArray;
boundedArray* sortSubstrings(char *str, int K)
{
    int len=strlen(str),index=0,tindex=0,min;
    char temp[K];
    char** words=malloc(sizeof(char *) * (len/K));
    for (int i=0;i<len/K;i++)
        words[i]=malloc(sizeof(char) * (K + 1));
    for (int i=0;i<len;i+=K)
    {
        tindex=0;
        for (int j=i,ctr=0;ctr<K;j++,ctr++)
            words[index][tindex++]=str[j];
        words[index][tindex]='\0';

        index++;
    }
    for (int i=0;i<index;i++)
    {
        min=i;
        for (int j=i;j<index;j++)
        {
            if (strcmp(words[j],words[min])<=0)
                min=j;
        }
        strcpy(temp,words[i]);
        strcpy(words[i],words[min]);
        strcpy(words[min],temp);
    }
    
    boundedArray* barray=malloc(sizeof(boundedArray));
    barray->words=words;
    barray->SIZE=index;
    return barray;
}
int main()
{
    char str[101];
    int K;
    scanf("%s\n%d", str, &K);
    boundedArray *bArr = sortSubstrings(str, K);
    if(bArr == NULL || bArr->SIZE == 0 || bArr->words == NULL
            || bArr->words[0][0] == '\0' || bArr->words[0][0] == ' ')
    {
        printf("String values are not formed\n");
    }
    for(int index = 0; index < bArr->SIZE; index++)
    {
        printf("%s ", bArr->words[index]);
    }
    return 0;
}
