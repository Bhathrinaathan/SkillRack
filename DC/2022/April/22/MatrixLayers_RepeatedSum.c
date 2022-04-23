#include<stdio.h>
#include<stdlib.h>
int ExistInList(int i,int *arr,int index)
{
    for (int j=0;j<index;j++)
        if (arr[i]==arr[j] && i!=j)
            return 1;
    return 0;
}
int main()
{
    int N,len;
    scanf("%d",&N);
    len=N-1;
    int mat[N][N],sum[N],index=0;
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            scanf("%d",&mat[i][j]);
    for (int t=0;t<N/2;t++)
    {
        sum[index]=0;
        for (int i=t;i<=len;i++)
        {
            sum[index]+=mat[t][i];
            sum[index]+=mat[len][i];
        }
        for (int i=t+1;i<len;i++)
        {
            sum[index]+=mat[i][t];
            sum[index]+=mat[i][len];
        }
        len--;index++;
        
    }
    if (N%2==1)
        sum[index++]=mat[N/2][N/2];
    for (int i=0;i<index;i++)
    {
        if (ExistInList(i,sum,index)){
            printf("%d ",sum[i]);return;
        }
    }
    printf("-1");
}
