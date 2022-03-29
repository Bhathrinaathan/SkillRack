#include<stdio.h>
#include<stdlib.h>
int numNotInList(int n,int arr[],int index)
{
    if (index==0)
        return 1;
    for (int i=0;arr[i]!=NULL;i++)
        if (arr[i]==n)
            return 0;
    return 1;
}
int durationOfCalls(int h1,int m1,int s1,int h2,int m2,int s2)
{
    int duration=(s2-s1);
    duration+=(m2-m1)*60;
    duration+=(h2-h1) * 3600;
    return duration;
}
int main()
{
    int N;
    scanf("%d",&N);
    int h1,h2,m1,m2,s1,s2;
    int duration[N],index=0,i,j,max=0;
    long long int Num[N],temp;
    for ( i=0;i<N;i++)
    {
        temp=0;
        scanf("%lld %d:%d:%d %d:%d:%d",&temp,&h1,&m1,&s1,&h2,&m2,&s2);
        if (numNotInList(temp,Num,index)==1)
        {
            Num[index]=temp;
            duration[index]=durationOfCalls(h1,m1,s1,h2,m2,s2);
            index++;
        }
        else 
        {
            for (j=0;j<index;j++)
                if (Num[j]==temp)
                    break;
            duration[j]+=durationOfCalls(h1,m1,s1,h2,m2,s2);
        }
    }
    for (i=0;i<index;i++)
        if(max<=duration[i])
            max=duration[i];
    for (i=0;i<index;i++)
    {
        if (duration[i]==max)
            printf("%lld\n",Num[i]);
    }
}
