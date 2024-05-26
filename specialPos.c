#include<stdio.h>
#include<stdlib.h>

void print_2D(long long **arr, int row, int col) {
    for(int i = 0;i < row;i++) {
        for(int j = 0;j < col;j++) {
            printf("%lld ", arr[i][j]);
        }
        printf("\n");
    }
}

int numSpecial(int** mat, int matSize, int* matColSize) {
    int colSize = *matColSize;
    int rowSize = matSize;
    int *rowSum = (int *)calloc(rowSize, sizeof(int));
    int *colSum = (int *)calloc(colSize, sizeof(int));
    int res = 0;
    for(int i = 0;i < rowSize;i++) {
        for(int j = 0;j < colSize;j++) {
            rowSum[i] += mat[i][j]; 
            colSum[j] += mat[i][j];
        }
    }

    for (int i = 0;i < rowSize;i++) {
        for (int j = 0;j < colSize;j++) {
            if(mat[i][j]) {
                res += (rowSum[i] == 1 && colSum[j] == 1);
            }
        }
    }
    return res;
}

int main() {
    int row = 3, col;
    int **arr = (int **)calloc(3, sizeof(int*));
    for(int i = 0;i < row;i++) {
        arr[i] = (int *)calloc(3, sizeof(int));
    }
    //arr[0][0] = 1;
    //arr[1][1] = 1;
    arr[2][0] = 1;
    int ret = numSpecial(arr, row, &col);
    printf("The value is %d\n", ret);

    return 0;
}