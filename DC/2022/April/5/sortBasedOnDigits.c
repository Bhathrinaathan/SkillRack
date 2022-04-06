#include <stdio.h>
#include <stdlib.h>
int numberOfDigits(int N)
{
    int count=0;
    while(N>0){count++;N/=10;}
    return count;
}
int MSD(int val,int digits,int diff)
{
    char S[12];
    sprintf(S,"%d",val);
    return S[diff-1]-'0';
    //return val%10;
}
void swap(int *X,int *Y)
{
    int temp=*X;
    *X=*Y;
    *Y=temp;
}
void sortBasedOnDigits(int SIZE, int *arr)
{
    int digits[SIZE],min,temp,diff;
    for (int i=0;i<SIZE;i++)
        digits[i]=numberOfDigits(arr[i]);
        
    for (int i=0;i<SIZE-1;i++)
    {
        min=i;
        for (int j=i+1;j<SIZE;j++)
        {
            if (MSD(arr[j],digits[j],1)<MSD(arr[min],digits[min],1))
                min=j;
            else if (MSD(arr[j],digits[j],1)==MSD(arr[min],digits[min],1))
            {
                if (digits[j]==1 || digits[min]==1)
                    min=(digits[j]==1)?j:min;
                else
                {
                    diff=2;
                    while(MSD(arr[j],digits[j],diff)==MSD(arr[min],digits[min],diff) && diff<=digits[j]&&diff<=digits[min])
                        diff++;
                    if(MSD(arr[j],digits[j],diff)<MSD(arr[min],digits[min],diff))
                        min=j;
                    else if (MSD(arr[j],digits[j],diff)==MSD(arr[min],digits[min],diff))
                    {
                        if (diff==digits[j])
                            min=j;
                    }
                }
            }
        }
        swap(&arr[i],&arr[min]);
        swap(&digits[i],&digits[min]);
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    int arr[N];
    for(int index = 0; index < N; index++)
    {
        scanf("%d", &arr[index]);
    }
    sortBasedOnDigits(N, arr);
    for(int index = 0; index < N; index++)
    {
        printf("%d ", arr[index]);
    }
    return 0;
}
