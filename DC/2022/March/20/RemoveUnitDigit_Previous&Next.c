#include<stdio.h>
#include<stdlib.h>

int main()
{
    int N,T,i,count=0,index=0,digit,flag=0;
    scanf("%d",&N);
    int arr[N],sum=0;
    for (int i=0;i<N;i++)
        scanf("%d ",&arr[i]);
    scanf("%d",&T);
    while (count<T)
    {
        flag=0;
        digit=arr[index]%10;
        if (arr[index]!=0)
            arr[index]/=10;
        if (arr[index]<=0)
        {
            for (int i=index+1;i<N;i++)
                arr[i-1]=arr[i];
            arr[N- 1]=0;
            flag=1;
            N--;
        }
        if (digit%2==0 && flag==0)
            index++;
        else if (digit%2==1)
            index--;
        if (index<0)
            index=N-1;
        else if (index>=N)
            index=0;
        count++;
    }
    for (int i=0;i<N;i++)
        sum+=arr[i];
    if (sum==0)
        printf("-1");
    else
        printf("%d",sum);
}
