#include<stdio.h>
#include<stdlib.h>
int main()
{
    int N,T,count;
    scanf("%d",&T);
    for (int t=0;t<T;t++)
    {
        scanf("%d",&N);
        int arr[N];
        count=0;
        for (int i=0;i<N;i++)
            scanf("%d",&arr[i]);
        for (int i=1;i<N-1;i++)
          if (arr[i]>arr[i-1] && arr[i]>arr[i+1])
              count++;
        printf("%d",count);
    }
}
