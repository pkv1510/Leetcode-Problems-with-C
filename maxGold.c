#include<stdio.h>
#include<stdlib.h>

int row, col;

void print_2D(int **arr, int row, int col) {
    for(int i = 0;i < row;i++) {
        for(int j = 0;j < col;j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void getGold(int** grid, int i, int j, int gold, int *totalGold) {
    if(i < 0 || i >= row || j < 0 || j >= col || !grid[i][j])
        return;

    int tmp = grid[i][j];
    gold += tmp;
    *totalGold = (gold > *totalGold) ? gold : *totalGold;
    grid[i][j] = 0;

    getGold(grid, i, j + 1, gold, totalGold);
    getGold(grid, i + 1, j, gold, totalGold);
    getGold(grid, i, j - 1, gold, totalGold);
    getGold(grid, i - 1, j, gold, totalGold);
    grid[i][j] = tmp;
}

int getMaximumGold(int** grid, int gridSize, int* gridColSize) {
    row = gridSize;
    col = *gridColSize;
    int totalGold = 0;

    for(int i = 0;i < row;i++) {
        for(int j = 0;j < col;j++) {
            if (grid[i][j])
                getGold(grid, i, j, 0, &totalGold);
        }
    }
    return totalGold;
}

int main() {
    row = 3;
    col = 3;
    int **arr = (int **)calloc(row, sizeof(int*));
    for(int i = 0;i < row;i++) {
        arr[i] = (int *)calloc(col, sizeof(int));
    }
    arr[0][1] = 6;
    arr[1][0] = 5;
    arr[1][1] = 8;
    arr[1][2] = 7;
    arr[2][1] = 9;

    print_2D(arr, row, col);
    printf("The maximum gold collected can be %d\n", getMaximumGold(arr,row, &col));

    return 0;
}