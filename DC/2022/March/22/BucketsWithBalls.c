#include<stdio.h>
#include<stdlib.h>

int main()
{
    int T,N,K,count=0;
    scanf("%d %d",&T,&N);
    int buckets[T][N];
    int b=T- 1;
    for (int i=0;i<T;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&buckets[i][j]);
    scanf("%d",&K);
    for (int j=0;j<N;j++)
    {
        if (buckets[b][j]>=K)
        {buckets[b][j]=0;count++;}
    }    
    for (int i=b- 1;i>=0;i--)
    {
        for (int j=0;j<N;j++)
        {
            buckets[b][j]+=buckets[i][j];
            if (buckets[b][j]>=K)
            {
                buckets[b][j]=0;
                count++;
            }
        }
    }
    printf("%d",count*K);
}
