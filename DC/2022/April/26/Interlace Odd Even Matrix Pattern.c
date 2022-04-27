#include<stdio.h>
#include<stdlib.h>

int main()
{
    int N;
    scanf("%d",&N);
    int odd=1,even=(N%2==0)?N*N:(N*N)-1,toggle=0;
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            if (toggle==0)
            {   printf("%d ",odd);odd+=2;toggle=1;    }
            else
            {   printf("%d ",even);even-=2;toggle=0;  }
        }
        printf("\n");
    }
}
