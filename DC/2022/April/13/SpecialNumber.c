#include<stdio.h>
#include<stdlib.h>
int reverseOfTheNumber(int N)
{
    int rev=0;
    while(N>0)
    {
        rev=rev * 10 + N%10;
        N/=10;
    }
    return rev;
}
int main()
{
    int N;
    scanf("%d",&N);
    int start=N/2;
    while (start<N)
    {
        if (start+reverseOfTheNumber(start)==N)
        {
            printf("true");
            return;
        }
        start++;
    }
    printf("false");
}
