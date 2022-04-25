#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num1,num2,K,bin1[100],bin2[100],index1=0,index2=0;
    int val=0,two=1,t;
    scanf("%d %d\n%d",&num1,&num2,&K);
    while(num1>0)
    {   bin1[index1++]=num1%2;num1/=2;    }
    while(num2>0)
    {   bin2[index2++]=num2%2;num2/=2;    }
    
    for (int i=0,j=index1-1;i<j;i++,j--)
    {   t=bin1[i];bin1[i]=bin1[j];bin1[j]=t;   }
    for  (int i=0,j=index2-1;i<j;i++,j--)
    {   t=bin2[i];bin2[i]=bin2[j];bin2[j]=t;    }
    
    for (int i=index2-1,j=0;j<K;i--,j++)
    {   val=val + (bin2[i]*two);two*=2;     }
    for (int i=K-1;i>=0;i--)
    {   val=val + (bin1[i]*two);two*=2;     }
    printf("%d",val);
}
