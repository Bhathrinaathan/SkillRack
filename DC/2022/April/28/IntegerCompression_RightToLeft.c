#include<stdio.h>
#include<stdlib.h>

int main()
{
    long int N,newVal,temp;
    long long int tens=1;
    scanf("%ld",&N);
    newVal=N;
    printf("%ld\n",N);
    while(newVal>=10)
    {
        N=newVal;
        newVal=0;
        tens=1;
        while (N>0)
        {
            temp=N%10;
            if (N>=10)
                temp+=((N/10)%10);
            N/=100;
            newVal=newVal+temp*tens;
            tens*=10;
            if (temp>=10)
                tens*=10;
        }
        printf("%ld\n",newVal);
    }
}
