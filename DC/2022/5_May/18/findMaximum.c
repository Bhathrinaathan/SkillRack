#include <stdio.h>
#include <stdlib.h>

typedef struct BoundedArray
{
    int M, N;
    int **matrix;
} boundedArray;
boundedArray* findMaximum(int R, int C, int *matrix, int K)
{
    int M=R/K,N=C/K,max,row,col,r=0,c=0;
    int** maxMatrix=malloc(sizeof(int*)*M);
    for (int i=0;i<M;i++)
        maxMatrix[i]=malloc(sizeof(int)*N);
    boundedArray* barr=malloc(sizeof(boundedArray));
    
    for (int i=0,r=0;i<R;i+=K,r++)
    {
        for (int j=0,c=0;j<C;j+=K,c++)
        {
            max=0;
            for  (int row=i;row<(i+K);row++)
            {
                for (int col=j;col<(j+K);col++)
                {
                    if (max<matrix[(row*C)+col])
                        max=matrix[(row*C)+col];
                }
            }
            maxMatrix[r][c]=max;
        }
    }
    barr->M=M;
    barr->N=N;
    barr->matrix=maxMatrix;
    return barr;
} // End of findMaximum function
int main()
{
    int R, C, K;
    scanf("%d %d", &R, &C);
    int matrix[R][C];
    for(int row = 0; row < R; row++)
    {
        for(int col = 0; col < C; col++)
        {
            scanf("%d", &matrix[row][col]);
        }
    }
    scanf("%d", &K);
    boundedArray *bArr = findMaximum(R, C, matrix, K);
    if(bArr == NULL)
    {
        printf("Matrix is not formed\n");
    }
    if(bArr->M <= 0 || bArr->N <= 0)
    {
        printf("Invalid size for the matrix\n");
    }
    for(int row = 0; row < bArr->M; row++)
    {
        for(int col = 0; col < bArr->N; col++)
        {
            printf("%d ", bArr->matrix[row][col]);
        }
        printf("\n");
    }
    return 0;
}
