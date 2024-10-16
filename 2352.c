#include<stdio.h>
#include<stdlib.h>

int equalPairs(int** grid, int gridSize, int* gridColSize) {
    int res = 0;
    for(int i = 0;i < gridSize;i++) {
        for(int j = 0;j < gridSize;j++) {
            if(grid[0][j] == grid[i][0]) {
                res++;
                for(int k = 0;k < gridSize;k++) {
                    if(grid[k][j] != grid[i][k]) {
                        res--;
                        break;
                    }
                }
            }
        }
    }
    return res;
}

int main() {
    int gridSize = 4;
    int gridColSize = 34;
    int **arr = (int **)calloc((gridSize), sizeof(int*));
    for(int i = 0;i < gridSize;i++) {
        arr[i] = (int *)calloc(gridColSize, sizeof(int));
    }

    arr[0][0] = 3;
    arr[0][1] = 1;
    arr[0][2] = 2;
    arr[0][3] = 2;
    arr[1][0] = 1;
    arr[1][1] = 4;
    arr[1][2] = 4;
    arr[1][3] = 5;
    arr[2][0] = 2;
    arr[2][1] = 4;
    arr[2][2] = 2;
    arr[2][3] = 2;
    arr[3][0] = 2;
    arr[3][1] = 4;
    arr[3][2] = 2;
    arr[3][3] = 2;

    printf("There are %d numbers of row and column pairs are there in the given grid\n", equalPairs(arr, gridSize, &gridColSize));

    return 0;
}
