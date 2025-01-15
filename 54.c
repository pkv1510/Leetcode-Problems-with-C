#include<stdio.h>
#include<stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int *ret = (int *)malloc((matrixSize * (*matrixColSize)) * sizeof(int));
    int minRow = 0, minCol = 0;
    int maxRow = matrixSize-1, maxCol = *matrixColSize-1;
    int idx = 0;

    while(minRow <= maxRow && minCol <= maxCol) {
        for(int i = minCol;i <= maxCol;i++) {
            ret[idx++] = matrix[minRow][i];
        }
        minRow++;
        if(minRow > maxRow) break;
        for(int i = minRow;i <= maxRow;i++) {
            ret[idx++] = matrix[i][maxCol];
        }
        maxCol--;
        if(minCol > maxCol) break;
        for(int i = maxCol;i >= minCol;i--) {
            ret[idx++] = matrix[maxRow][i];
        }
        maxRow--;
        if(minRow > maxRow) break;
        for(int i = maxRow;i >= minRow;i--) {
            ret[idx++] = matrix[i][minCol];
        }
        minCol++;
    }
    *returnSize = idx;
    return ret;
}

int main() {
    int rows=6, cols=4, a= 1;

    int **arr;
    arr = (int**)malloc(rows * sizeof(int*));
    for(int i = 0;i< rows;i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
        for(int j = 0;j < cols;j++) {
            arr[i][j] = a++;
        }
    }

    printf("The matrix is as: \n");

    for(int i = 0;i< rows;i++) {
        for(int j = 0;j < cols;j++) 
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    int returnSize = 0;
    int *ret = spiralOrder(arr, rows, &cols, &returnSize);

    printf("The matrix in spiral form is as: ");
    for(int i = 0;i< returnSize;i++) {
            printf("%d ", ret[i]); 
    }
    printf("\n");

    return 0;
}