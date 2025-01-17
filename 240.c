#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    for(int i = 0;i < matrixSize;i++) {
        if(matrix[i][0] > target)
            break;
        else if(matrix[i][*matrixColSize -1] < target)
            continue;
        else {
            for(int j = 0;j < *matrixColSize;j++) {
                if(matrix[i][j] == target)
                    return true;
                else if(matrix[i][j] > target) {
                    *matrixColSize = j;
                    break;
                }
                else if(matrix[i][*matrixColSize -1] < target)
                    break;
            }
        }
    }
    return false;
}

int main() {
    int rows=4, cols=4, a= 1;

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
    int target = 19;

    if(searchMatrix(arr, rows,&cols, target))
        printf("The target value %d resides in the matrix\n", target);
    else
        printf("The target value %d does not reside in the matrix\n", target);
}