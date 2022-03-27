#include <stdio.h>
#include <stdlib.h>

typedef struct BoundedArray
{
    int R, C;
    int **matrix;
} boundedArray;

boundedArray* removeRowsWithSameValue(int R, int C, int *matrix)
{
    boundedArray *barr=malloc(sizeof(boundedArray));
    int** resMat=malloc(sizeof(int *)*R);
    for (int i=0;i<R;i++)
        resMat[i]=malloc(sizeof(int) * C);
    int rR=0,t=0;
    for (int i=0;i<R;i++)
    {
        t=0;
        while(matrix[i*C + t]==matrix[i*C + t+1] && t+1<C)
            t++;
        if (t!=C-1)
        {
            for (int j=0;j<C;j++)
            {
                resMat[rR][j]=matrix[i*C + j];
            }
            rR++;
        }
    }
    if (rR==0)
    {    rR=1;C=1;resMat[0][0]=-1;}
    barr->matrix=resMat;
    barr->R=rR;
    barr->C=C;
    return barr;
} // End of removeRowsWithSameValue function

int main()
{
    int R, C;
    scanf("%d %d", &R, &C);
    int matrix[R][C];
    for(int row = 0; row < R; row++)
    {
        for(int col = 0; col < C; col++)
        {
            scanf(" %d", &matrix[row][col]);
        }
    }
    boundedArray *bArr = removeRowsWithSameValue(R, C, matrix);
    if(bArr == NULL)
    {
        printf("Matrix is not formed\n");
    }
    if(bArr->R <= 0 || bArr->C <= 0)
    {
        printf("Invalid size for the revised matrix\n");
    }
    for(int row = 0; row < bArr->R; row++)
    {
        for(int col = 0; col < bArr->C; col++)
        {
            printf("%d ", bArr->matrix[row][col]);
        }
        printf("\n");
    }
    return 0;
}
