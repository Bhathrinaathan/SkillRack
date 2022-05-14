#include<stdio.h>
#include<stdlib.h>
int sumOfDigits(int N)
{ 
    int sum=0;
    while(N>0)
    { 
        sum+=(N%10);
        N/=10;
    }
    return sum;
}
int main()
{
    int R;
    scanf("%d",&R);
    R=sumOfDigits(R);
    while(R>26)
        R=sumOfDigits(R);
    printf("%c",R - 1 + 'A');
}
