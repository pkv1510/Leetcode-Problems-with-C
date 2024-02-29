#include<stdio.h>
#include<stdlib.h>

int findPaths1(int m, int n, int maxMove, int startRow, int startColumn) {
    int ret = 0;
    if(startRow == m || startColumn == n) 
        return ret;

    while(maxMove > 0) {
        if(!startRow || (startRow == (m - 1))) {
            ret += 1;
            if(!startColumn || (startColumn == n - 1))
                ret += 1;

            maxMove--;
            ret += findPaths1(m, n, maxMove, startRow + 1, startColumn);
        } else {
            if(!startColumn || (startColumn == n - 1)) {
                ret += 1;
                maxMove--;
                ret += findPaths1(m, n, maxMove, startRow + 1, startColumn);
            } else {
                ret+= 1;
                maxMove--;
                ret += findPaths1(m, n, maxMove, startRow, startColumn - 1);
            }
        }
    }
    ret %= 1000000007;

    return ret;
}

long long numPaths(int m, int n, int maxMove, int row, int col, long long ***arr) {
    if(row < 0 || row == m || col < 0 || col == n)
        return 1;
    
    if(!maxMove)
        return 0;
    
    if(arr[row][col][maxMove] != -1)
        return arr[row][col][maxMove];
    
    long long num = (
                    numPaths(m, n, maxMove - 1, row - 1, col, arr) % 1000000007 +
                    numPaths(m, n, maxMove - 1, row, col - 1, arr) % 1000000007 +
                    numPaths(m, n, maxMove - 1, row + 1, col, arr) % 1000000007 +
                    numPaths(m, n, maxMove - 1, row, col + 1, arr) % 1000000007
    ) % 1000000007;

    arr[row][col][maxMove] = num;

    return num;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    int i, j, k;
    long long ***arr = (long long***)malloc(m * sizeof(long long**));
    for (i = 0; i < m; ++i) {
        arr[i] = (long long**)malloc(n * sizeof(long long*));
        for (j = 0; j < n; ++j) {
            arr[i][j] = (long long*)malloc((maxMove + 1) * sizeof(long long));
            for (k = 0; k <= maxMove; ++k) {
                arr[i][j][k] = -1;
            }
        }
    }
    int result = (int)numPaths(m, n, maxMove, startRow, startColumn, arr);

    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);

    return result;
}

int main()
{
    int row = 2, col = 2;
    int num;
    printf("Enter the max numer of moves\n");
    scanf("%d", &num);

    printf("The total number of paths for getting out of bounds are %d\n", findPaths1(row, col, num, 0, 0));
    
    return 0;
}