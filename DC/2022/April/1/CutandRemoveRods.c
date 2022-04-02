#include<stdio.h>
#include<stdlib.h>
int minimumOfRods(int rods[],int N)
{
    int min=rods[0];
    for (int i=0;i<N;i++)
        if (rods[i]<min)
            min=rods[i];
    return min;
}
int main()
{
    int N,minLength=0,i;
    scanf("%d",&N);
    int rods[N];
    for (int i=0;i<N;i++)
        scanf("%d",&rods[i]);
    printf("%d\n",N);    
    while (N>0)
    {
        minLength=minimumOfRods(rods,N);
        i=0;
        while(i<N)
        {
            rods[i]-=minLength;
            if (rods[i]<=0)
            {
                for (int j=i;j<N-1;j++)
                    rods[j]=rods[j+1];
                N--;
                i--;
            }
            i++;
        }
        if (N>0)
            printf("%d\n",N);
    }
}
