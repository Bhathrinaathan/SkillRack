#include<stdio.h>
#include<stdlib.h>

int main()
{
    int N;
    scanf("%d",&N);
    int matrix[N][N],sum1=0,sum2=0;
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            scanf("%d",&matrix[i][j]);
            if (i==0)
                sum2+=matrix[i][j];
            if (i==N-1)
                sum1+=matrix[i][j];
        }
    }
    for (int i=1;i<N;i++)
        sum2+=matrix[i][N-1];
    for (int i=0;i<N-1;i++)
        sum1+=matrix[i][0];
    if (sum1==sum2)
        printf("YES");
    else
        printf("NO");
}
