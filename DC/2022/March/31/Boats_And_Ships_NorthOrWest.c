#include<stdio.h>
#include<stdlib.h>
int shipsInsidePort(int R,int C,char port[][C])
{
    int count=0;
    for(int i=0;i<R;i++)
        for (int j=0;j<C;j++)
            if (port[i][j]=='#')
                count++;
    return count;
}
int NoObstacleInWayCol(int R,int C,char port[][C],int r,int c)
{
    for (int i=0;i<r;i++)
        if (port[i][c]=='#')
            return 0;
    return 1;
}
int NoObstacleInWayRow(int R,int C,char port[][C],int r,int c)
{
    for (int i=0;i<c;i++)
        if (port[r][i]=='#')
            return 0;
    return 1;
}
int main()
{
    int R,C,row,col,minutes=1;
    scanf("%d %d",&R,&C);
    char port[R][C];
    for (row=0;row<R;row++)
        for (col=0;col<C;col++)
            scanf(" %c",&port[row][col]);
    while (shipsInsidePort(R,C,port)>=1)
    {
        if (minutes%2==1)
        {
            for (col=0;col<C;col++)
            {
                for (row=0;row<R;row++)
                {
                    
                    if (port[row][col]=='#' && port[row+1][col]=='#' && row<R-1)
                    {
                        if (NoObstacleInWayCol(R,C,port,row,col))
                        {
                            port[row][col]='*';port[row+1][col]='*';break;
                        }
                    }
                    else if ( (port[row][col]=='#' && port[row][col+1]!='#' && port[row][col-1]!='#') || (col==C-1 && port[row][col]=='#'))
                    {
                        if (NoObstacleInWayCol(R,C,port,row,col))
                        {
                            port[row][col]='*';break;
                        }
                    }
                }
            }
        }
        else if (minutes%2==0)
        {
            for (row=0;row<R;row++)
            {
                for (col=0;col<C;col++)
                {
                    if (port[row][col]=='#' && port[row][col+1]=='#' && col<C-1)
                    {
                        if (NoObstacleInWayRow(R,C,port,row,col))
                        {   port[row][col]='*';port[row][col+1]='*';break;   }
                    }else if ((port[row][col]=='#' && port[row+1][col]!='#' && port[row-1][col]!='#') || (row==R-1 && port[row][col]=='#'))
                    {
                        if (NoObstacleInWayRow(R,C,port,row,col))
                        {   port[row][col]='*';break;}
                    }
                }
            }
        }
        minutes++;
    }
    printf("%d ",minutes - 1);
}
