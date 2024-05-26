#include<stdio.h>
#include<stdlib.h>

void print_2D(int **arr, int row, int col) {
    for(int i = 0;i < row;i++) {
        for(int j = 0;j < col;j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void flipRow(int **grid, int i, int col) {
    for(int j = 0;j < col;j++)
        grid[i][j] ^= 1;
}

void flipCol(int **grid, int j, int row) {
    for(int i = 0;i < row;i++)
        grid[i][j] ^= 1;
}

int getVal(int num, int pow, int flag) {
    if(flag)
        num ^= 1;

    return ((1 << pow) * num);
}

void checkAndFlipCol(int **grid, int rowSize, int colSize, int col) {
    int currScore = 0, newScore = 0;
    for(int i = 0;i < rowSize;i++) {
        currScore += getVal(grid[i][col], (colSize - col - 1), 0);
        newScore += getVal(grid[i][col], (colSize - col - 1), 1);
    }
    if(newScore > currScore)
        flipCol(grid, col, rowSize);
}

int finalScore(int **grid, int row, int col) {
    int score = 0;
    for(int i = 0;i < row;i++) {
        for(int j = 0;j < col;j++) {
            score += getVal(grid[i][j], (col - j - 1), 0);
        }
    }
    return score;
}

int matrixScore(int** grid, int gridSize, int* gridColSize) {
    /*Make the first column 1*/
    int row = gridSize;
    int col = *gridColSize;
    for(int i = 0;i < row;i++) {
        if(!grid[i][0])
            flipRow(grid, i, col);
    }

    int score = 0;
    for(int i = 0;i < row;i++) {
        for(int j = 1;j < col;j++) {
            checkAndFlipCol(grid, row, col, j);
        }
    }

    return (finalScore(grid, row, col));
}

int main() {
    int row = 3, col = 4;
    int **arr = (int **)calloc(row, sizeof(int*));
    for(int i = 0;i < row;i++) {
        arr[i] = (int *)calloc(col, sizeof(int));
    }
    arr[0][2] = 1;
    arr[0][3] = 1;
    arr[1][0] = 1;
    arr[1][2] = 1;
    arr[2][0] = 1;
    arr[2][1] = 1;

    print_2D(arr, row, col);

    int score = matrixScore(arr, row, &col);
    printf("The maximum score can be %d\n", score);
    print_2D(arr, row, col);
}