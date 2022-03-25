#include<stdio.h>
#include<stdlib.h>

int main()
{
    int R,C,row,col,K,index=0,i=0;
    scanf("%d %d",&R,&C);
    char Mat[R][C];
    for (row=0;row<R;row++)
        for (col=0;col<C;col++)
            scanf(" %c",&Mat[row][col]);
    scanf("%d",&K);
    int N=(R*C)/(K*K);
    int arr=0;
    char S[N+ 1][K*K + 1];
    for (int outR=0;outR<R;outR+=K)
    {
        for (int outC=0;outC<C;outC+=K)
        {
            i=0;
            for (row=outR;row<outR+K;row++)
            {
                for (col=outC;col<outC+K;col++)
                {
                    S[index][i]=Mat[row][col];
                    i++;
                }
            }
            S[index][K*K]='\0';
            index=index+ 1;
        }
    }
    for (int j=0;j<N;j++)
    {
        arr=0;
        for (int k=0;k<N;k++)
        {
            if (k!=j){
            if (strcmp(S[j],S[k])==0 )
            {   arr=1;break;}}
        }
        if (arr==0)
        {
            i=0;
            for (row=0;row<K;row++)
            {
                for (col=0;col<K;col++)
                    printf("%c ",S[j][i++]);
                printf("\n");
            }
            return;
        }
    }
    printf("-1");
}
