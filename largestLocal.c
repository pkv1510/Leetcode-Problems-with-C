#include<stdio.h>
#include<stdlib.h>

#define INT_MIN (-2147483648)

void print_2D(int **arr, int row, int col) {
    for(int i = 0;i < row;i++) {
        for(int j = 0;j < col;j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int findMax(int **arr, int row, int col) {
    int max = INT_MIN;
    for(int i = row;i < (row + 3);i++) {
        for(int j = col;j < (col + 3);j++) {
            if(arr[i][j] > max)
                max = arr[i][j];
        }
    }
    return max;
}

int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int rowSize = gridSize;
    int colSize = *gridColSize;
    *returnSize = gridSize - 2;
    *returnColumnSizes = (int*)malloc((gridSize - 2) * sizeof(int));
    
    for (int i = 0; i < (gridSize - 2); i++) {
        (*returnColumnSizes)[i] = gridSize - 2;
    }

    int **temp = (int **)calloc((rowSize - 2), sizeof(int*));
    for(int i = 0;i < (rowSize - 2);i++) {
        temp[i] = (int *)calloc(colSize - 2, sizeof(int));
    }

    for(int i = 0;i < (rowSize - 2);i++) {
        for(int j = 0;j < (colSize - 2);j++) {
            temp[i][j] = findMax(grid, i, j);
        }
    }
    return temp;
}

int main() {
    int row = 5, col = 5;
    int **arr = (int **)calloc((row), sizeof(int*));
    for(int i = 0;i < row;i++) {
        arr[i] = (int *)calloc(col, sizeof(int));
    }

    for(int i = 0;i < row;i++) {
        for(int j = 0;j < col;j++) {
            arr[i][j] = 1;
        }
    }
    arr[2][2] = 2;
    print_2D(arr, row, col);

    int colSize, rowSize;
    int *colsize = &colSize;
    int **res = largestLocal(arr, row, &col, &rowSize, &colsize);

    print_2D(res, rowSize, *colsize);

    return 0;
}