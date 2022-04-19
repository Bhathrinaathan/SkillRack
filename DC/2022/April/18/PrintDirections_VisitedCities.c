#include<stdio.h>
#include<stdlib.h>

int main()
{
    int R,C,ctr=1,max;
    scanf("%d %d",&R,&C);
    int mat[R][C];
    char t[3];
    for (int i=0;i<R;i++)
    {
        for (int j=0;j<C;j++)
        {
            scanf("%s",t);
            if (t[0]=='*')
                mat[i][j]=-1;
            else
            {
                mat[i][j]=atoi(t);
                if (mat[i][j]>max)
                    max=mat[i][j];
            }
        }
    }
    int i=0,j=0;
    while (ctr<=max)
    {
        if (mat[i][j+1]==ctr+1){
            printf("E ");
            j=j+1;
        }
        else if (mat[i+1][j]==ctr+1){
            printf("S ");
            i=i+1;
        }
        else if (mat[i][j-1]==ctr+1){
            printf("W ");
            j=j-1;
        }
        else if (mat[i-1][j]==ctr+1){
            printf("N ");
            i=i-1;
        }
        ctr++;
    }
}
