#include<stdio.h>
#include<stdlib.h>

int main()
{
    int R,C,row,col,len,nr,nc,index;
    scanf("%d %d",&R,&C);
    char Mat[R][C][10];
    int rdiff[8]={-1,-1,-1,0,1,1,1,0};
    int cdiff[8]={-1,0,1,1,1,0,-1,-1};
    for (row=0;row<R;row++)
        for  (col=0;col<C;col++)
            scanf("%s ",Mat[row][col]);
    for (row=0;row<R;row++)
    {
        for (col=0;col<C;col++)
        {
            if (isalpha(Mat[row][col][0]))
            {
                for (int k=0;k<8;k++)
                {
                    nr=row+rdiff[k];nc=col+cdiff[k];
                    if (nr>=0 && nr<R && nc>=0 && nc<C){
                    len=strlen(Mat[nr][nc]);
                    Mat[nr][nc][len]=Mat[row][col][0];
                    Mat[nr][nc][len+1]='\0';
                    }
                }
            }
        }
    }
    for (row=0;row<R;row++)
    {
        for (col=0;col<C;col++)
        {
            index=0;
            while (Mat[row][col][index]!='\0')
                printf("%c",Mat[row][col][index++]);
            printf(" ");
        }
        printf("\n");
    }
}
