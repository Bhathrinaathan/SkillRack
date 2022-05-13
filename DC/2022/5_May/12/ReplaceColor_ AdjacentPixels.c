#include<stdio.h>
#include<stdlib.h>
char oldColor,newColor,image[50][50];
int rD[8]={-1,-1,-1,0,1,1,1,0};
int cD[8]={-1,0,1,1,1,0,-1,-1};
int changeSurroundingColors(int pI,int pJ,int R,int C)
{
    int row,col;
    for (int i=0;i<8;i++)
    {
        row=pI+rD[i];
        col=pJ+cD[i];
        if (row>=0&&row<R&&col>=0&&col<C&&image[row][col]==oldColor)
        {
            image[row][col]=newColor;
            changeSurroundingColors(row,col,R,C);
        }
    }
    return 0;
}
int main()
{
    int R,C,X,Y,row,col;
    char Ch;
    scanf("%d %d",&R,&C);
    for (int i=0;i<R;i++)
        for (int j=0;j<C;j++)
            scanf(" %c",&image[i][j]);
    scanf("%d %d %c",&X,&Y,&Ch);
    X--;Y--;
    newColor=Ch;
    oldColor=image[X][Y];
    for (int i=0;i<8;i++)
    {
        row=X+rD[i];col=Y+cD[i];
        if (image[row][col]==oldColor){
            changeSurroundingColors(row,col,R,C);
            image[row][col]=newColor;
        } 
    }
    image[X][Y]=newColor;
    for (int i=0;i<R;i++)
    {
        for (int j=0;j<C;j++)
            printf("%c ",image[i][j]);
        printf("\n");
    }
}
