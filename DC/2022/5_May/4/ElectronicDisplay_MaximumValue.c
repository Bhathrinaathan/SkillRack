#include<stdio.h>
#include<stdlib.h>
int main()
{
    int Segment[]={6,2,5,5,4,5,6,3,7,6};
    int N,maxiVal=0,temp;
    scanf("%d ",&N);
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            for (int k=0;k<10;k++)
            {
                for (int l=0;l<10;l++)
                {
                    if (N==(Segment[i]+Segment[j]+Segment[k]+Segment[l]))
                    {
                        temp=i*1000+j*100+k*10+l;
                        if (temp>maxiVal)
                            maxiVal=temp;
                    }
                }
            }
        }
    }
    printf("%d",temp);
}
