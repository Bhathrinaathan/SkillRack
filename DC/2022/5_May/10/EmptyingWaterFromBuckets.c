#include<stdio.h>
#include<stdlib.h>

int main()
{
    int N,sum=0;
    scanf("%d",&N);
    int max[N],buckets[N],temp;
    for (int i=0;i<N;i++)
        scanf("%d",&max[i]);
    for  (int i=0;i<N;i++)
        scanf("%d",&buckets[i]);
    for (int i=0;i<N-1;i++)
    {
        temp=max[i + 1]- buckets[i+ 1];
        if  (temp<=buckets[i])
        {
            buckets[i+1]=max[i+1];
            buckets[i]-=temp;
        }
        else
        {
            buckets[i+1]+=buckets[i];
            buckets[i]=0;
        }
    }
    for (int i=0;i<N-1;i++)
        sum+=buckets[i];
    printf("%d %d",buckets[N-1],sum);
}
