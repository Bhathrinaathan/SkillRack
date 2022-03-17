#include <stdio.h>
#include <stdlib.h>

typedef struct BoundedArray
{
    int SIZE;
    int *arr;
} boundedArray;
boundedArray* getArrayFromString(char *str, int K)
{
    int len=strlen(str),index=0,zeros=0,val,flag;
    boundedArray *barr=malloc(sizeof(boundedArray));
    int *arr=malloc( sizeof(int) * (strlen(str)/K));
    
    for (int i=0;i<len;i+=K)
    {
        zeros=1;val=0;flag=0;
        for (int j=i;j<i+K;j++)
        {
            if (str[j]!='0')
                flag=1;
            if (str[j]=='0' && flag==0)
                zeros*=10;
            val=val*10 + str[j]-'0';
        }
        arr[index++]=val*zeros;
    }
    barr->arr=arr;
    barr->SIZE=index;
    return barr;
}
int main()
{
    char str[101];
    int K;
    scanf("%s\n%d", str, &K);
    boundedArray *bArr = getArrayFromString(str, K);
    for(int index = 0; index < bArr->SIZE; index++)
    {
        printf("%d ", bArr->arr[index]);
    }
    return 0;
}
