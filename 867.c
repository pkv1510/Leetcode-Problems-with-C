#include<stdio.h>
#include<stdlib.h>

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int **ret;
    *returnSize = *matrixColSize;

    ret = (int**)malloc((*returnSize) * sizeof(int*));
    *returnColumnSizes=(int*)malloc(*matrixColSize*sizeof(int));
    for(int i = 0;i < (*returnSize);i++) {
        ret[i] = (int *)malloc(matrixSize * sizeof(int));
        (*returnColumnSizes)[i] = matrixSize;
    }

    for(int i = 0;i< *matrixColSize;i++) {
        for(int j = 0;j < matrixSize;j++) {
            ret[i][j] = matrix[j][i];
        }
    }
    return ret;
}

int main() {
    int rows=3, cols=3, a= 1;

    int **arr;
    arr = (int**)malloc(sizeof(int*));
    for(int i = 0;i< rows;i++) {
        arr[i] = (int *)malloc(rows * sizeof(int));
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
    int *returnSize = &rows;
    int **returnColumnSizes = &returnSize;
    int **ret = transpose(arr, rows, &cols, returnSize, returnColumnSizes);
    
    printf("The transpose is : \n");
    for(int i = 0;i< *returnSize;i++) {
        for(int j = 0;j < **returnColumnSizes;j++) 
            printf("%d ", ret[i][j]);
        printf("\n");
    }
    return 0;
}