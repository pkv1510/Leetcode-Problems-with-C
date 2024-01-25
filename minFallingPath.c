#include<stdio.h>
#include <stdlib.h>

void print2D_Array(int** arr, int row, int col)
{
  int i,j;
  for (i=0; i < row; i++) {
    for (j=0; j < col; j++) 
        printf("%d ", arr[i][j]);
    printf("\n");
  }
  printf("\n");
}

int min2(int a, int b) {
    return a < b ? a : b;
}

int min3(int a, int b, int c) {
    return min2(min2(a, b), c);
}

int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize) {
    int min = __INT_MAX__;
    
    for(int i = matrixSize - 2;i >= 0;i--) {
        for(int j = 0;j < *matrixColSize;j++) {
            if(j == 0)
                matrix[i][j] = matrix[i][j] + min2(matrix[i + 1][j], matrix[i + 1][j + 1]);
            else if(j + 1 == *matrixColSize)
                matrix[i][j] = matrix[i][j] + min2(matrix[i + 1][j - 1], matrix[i + 1][j]);
            else
                matrix[i][j] = matrix[i][j] + min3(matrix[i + 1][j - 1], matrix[i + 1][j], matrix[i + 1][j + 1]);
        }
    }
    for(int i = 0;i < *matrixColSize;i++) {
        if(matrix[0][i] < min)
            min = matrix[0][i];
    }
    print2D_Array(matrix, matrixSize, *matrixColSize);
    return min;
}

int main()
{
    int rowSize = 4, i = 0;
    int colSize = 4;
    int **matrix = (int**)malloc(sizeof(int) * 3);
    for (int r = 0; r < rowSize; r++) {
        matrix[r] = (int *)malloc(3 * sizeof(int));
    }
    for (int r = 0; r < rowSize; r++) {
        for (int q = 0; q < colSize; q++) {
            matrix[r][q] = i++;
        }
        matrix[3][2] = 15;
    }

    print2D_Array(matrix, rowSize, colSize);
    printf("The minimum sum of falling path is %d\n", minFallingPathSum(matrix, rowSize, &colSize));

    return 0;
}