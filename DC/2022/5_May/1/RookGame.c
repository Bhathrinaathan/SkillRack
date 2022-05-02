#include<stdio.h>
#include<stdlib.h>
int row=0,col=0;
int freeCellExist(int R,int C,int mat[R][C])
{
    row=0;col=0;
    int flag1=0,flag2;
    for (int i=0;i<R;i++)
    {
        for (int j=0;j<C;j++)
        {
            flag1=0;flag2=0;
            for (int r=0;r<R;r++)
            {    if (mat[r][j]==1){flag1=1;break;}}
            for (int c=0;c<C;c++)
            {   if (mat[i][c]==1){flag2=1;break;}}
            if (flag1==0 && flag2==0)
            {
                row=i;col=j;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int R,C,count=0;
    scanf("%d %d",&R,&C);
    int mat[R][C];
    for (int i=0;i<R;i++)
        for (int j=0;j<C;j++)
            scanf("%d",&mat[i][j]);
    while (freeCellExist(R,C,mat)==1)
    {
        mat[row][col]=1;
        count++;
    }
    if (count==1 || count%2==1)
        printf("A");
    else
        printf("B");
}
