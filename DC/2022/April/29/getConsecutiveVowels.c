#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BoundedArray
{
    int SIZE;
    char **vowels;
} boundedArray;
int isVowel(char ch)
{
    ch=tolower(ch);
    if (ch=='a' || ch=='e' || ch=='i'||ch=='o'||ch=='u')
        return 1;
    return 0;
}
boundedArray* getConsecutiveVowels(char str[])
{
    int len=strlen(str),index=0,sindex=0,flag=0;
    char **vowels=malloc(sizeof(char*) * len);
    for(int i=0;i<len;i++)
        vowels[i]=malloc(sizeof(char)*len);
    for (int i=0;i<len;i++)
    {
        flag=0;
        sindex=0;
        while(isVowel(str[i]))
        {   vowels[index][sindex++]=str[i];flag=1;i++;   }
        if (flag==1)
            index++;
    }
    boundedArray* barr=malloc(sizeof(boundedArray));
    if (index==0)
    {
        barr->SIZE=1;
        vowels[0]="-1";
    }
    else
        barr->SIZE=index;
    barr->vowels=vowels;
    return barr;
}
int main()
{
    char str[1001];
    scanf("%s", str);

    boundedArray *bArr = getConsecutiveVowels(str);

    if(bArr == NULL || bArr->SIZE == 0 || bArr->vowels == NULL
            || bArr->vowels[0][0] == '\0' || bArr->vowels[0][0] == ' ')
    {
        printf("String values are not formed\n");
    }
    for(int index = 0; index < bArr->SIZE; index++)
    {
        printf("%s\n", bArr->vowels[index]);
    }
    return 0;
}
