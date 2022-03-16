#include<stdio.h>
#include<stdlib.h>
int surroundingDigitSum(int R,int C,int mat[][C],int r,int c)
{
    int sum=0,N=mat[r][c],count=0;
    if (N>count && r>0 && c>0){
        sum+=mat[r-1][c-1];count++;}
    if (N>count && r>0){
        sum+=mat[r-1][c];count++;}
    if (N>count && r>0 && c<C-1){
        sum+=mat[r-1][c+1];count++;}
    if (N>count && c<C-1){
        sum+=mat[r][c+1];count++;}
    if (N>count && r<R-1 && c<C-1){
        sum+=mat[r+1][c+1];count++;}
    if (N>count && r<R-1){
        sum+=mat[r+1][c];count++;}
    if (N>count && c>0 && r<R-1){
        sum+=mat[r+1][c-1];count++;}
    if (N>count && c>0){
        sum+=mat[r][c-1];count++;}
    return sum;
}
int main()
{
    int R,C,row,col,n;
    scanf("%d %d",&R,&C);
    int matrix[R][C];
    for (row=0;row<R;row++)
        for (col=0;col<C;col++)
            scanf("%d",&matrix[row][col]);
    for (row=0;row<R;row++){
        for (col=0;col<C;col++)
            printf("%d ",surroundingDigitSum(R,C,matrix,row,col));
        printf("\n");
    }
}
