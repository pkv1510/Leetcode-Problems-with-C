#include<stdio.h>
#include<stdlib.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize) {

    for(int i = 0;i< *matrixColSize;i++) {
        for(int j = 0;j < i;j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for(int i = 0;i < matrixSize;i++) {
        int tempCol = *matrixColSize;
        for(int j = 0;j < *matrixColSize;j++) {
            if(j < matrixSize/2) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][--tempCol];
                matrix[i][tempCol] = temp;
            }
        }
    }
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

    rotate(arr, rows, &cols);
    printf("The matrix after rotation is : \n");
    for(int i = 0;i < rows;i++) {
        for(int j = 0;j < cols;j++) 
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    return 0;
}