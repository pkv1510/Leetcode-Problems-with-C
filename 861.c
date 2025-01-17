#include<stdio.h>
#include<stdlib.h>

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

    for(int i = 0;i < row;i++) {
        for(int j = 1;j < col;j++) {
            checkAndFlipCol(grid, row, col, j);
        }
    }

    return (finalScore(grid, row, col));
}

int main() {
    int rows=3, cols=4, a= 1;

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
    printf("The final matrix score is %d\n",matrixScore(arr, rows, &cols));
}