#include<stdio.h>
#include<stdlib.h>
int NumberOfDigits(long long int N)
{
    int count=0;
    if (N==0)
        return 1;
    while (N>0){count++;N/=10;}
    return count;
}
int EvenNumberDigitsExist(int d[],int index)
{
    for (int i=0;i<index;i++)
        if (d[i]%2==0)
            return 1;
    return 0;
}
int main()
{
    long long int N,arr[1880],tens=1,temp,ctr=0;
    int index=1,d[100],Size,min;
    scanf("%lld ",&N);
    arr[0]=N;
    while (EvenNumberDigitsExist(d,index))
    {
        Size=index;
        for (int i=0;i<Size;i++)
        {
            d[i]=NumberOfDigits(arr[i]);
            if (d[i]%2==0)
            {
                ctr=0;tens=1;
                while(ctr<(d[i]/2)){   tens*=10;ctr++;}
                temp=arr[i];
                arr[i]=temp%tens;
                d[i]=d[i]/2;
                arr[index]=temp/tens;
                d[index]=d[i]/2;
                index++;
            }
        }
    }
    
    for (int i=0;i<index;i++)
    {
        min=i;
        for (int j=i;j<index;j++)
            if (arr[j]<arr[min])
                min=j;
        temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
    for (int i=0;i<index;i++)
        printf("%lld ",arr[i]);
}
