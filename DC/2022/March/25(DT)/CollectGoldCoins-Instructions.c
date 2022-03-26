#include<stdio.h>
#include<stdlib.h>

int main()
{
    int R,C,row,col,rdiff,cdiff,coins=0,i=0;
    scanf("%d %d",&R,&C);
    int mat[R][C],visited[R][C];
    for (row=0;row<R;row++){
        for (col=0;col<C;col++){
    scanf("%d",&mat[row][col]);visited[row][col]=-1;}}
    char ch[50];
    scanf("%s",ch);
    int len=strlen(ch);
    row=0;
    col=0;
    coins+=mat[0][0];
    visited[0][0]=mat[0][0]+ 1;
    for (int i=0;i<len;i++)
    {
        if (ch[i]=='N'){rdiff=-1;cdiff=0;}
        else if (ch[i]=='E'){rdiff=0;cdiff=1;}
        else if (ch[i]=='S'){rdiff=1;cdiff=0;}
        else{rdiff=0;cdiff=-1;}
        row+=rdiff;
        col+=cdiff;
        if (visited[row][col]==-1)
        {
            coins+=mat[row][col];
            visited[row][col]=mat[row][col]+ 1;
        }
        else if (visited[row][col]>1)
        {
            visited[row][col]--;
            coins--;
        }
    }
    printf("%d",coins);
}
