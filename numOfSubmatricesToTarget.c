#include<stdio.h>
#include<stdlib.h>

void print2D_Array(int** arr, int row, int *col)
{
  int i,j;
  for (i=0; i < row; i++) {
    for (j=0; j < (*col); j++) 
        printf("%d ", arr[i][j]);
    printf("\n");
  }
  printf("\n");
}

int numSubmatrixSumTarget(int** matrix, int rows, int* cols, int target) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < *cols; j++) {
            matrix[i][j] += i > 0 ? matrix[i - 1][j] : 0;
            matrix[i][j] += j > 0 ? matrix[i][j - 1] : 0;
            matrix[i][j] -= i > 0 && j > 0 ? matrix[i - 1][j - 1] : 0;
        }
    }
    print2D_Array(matrix, rows, cols);

    int res = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < *cols; j++) {
            for (int k = 0; k <= i; k++) {
                for (int l = 0; l <= j; l++) {
                    int matSum = matrix[i][j];
                    matSum -= k > 0 ? matrix[k - 1][j] : 0;
                    matSum -= l > 0 ? matrix[i][l - 1] : 0;
                    matSum += k > 0 && l > 0 ? matrix[k - 1][l - 1] : 0;
                    if (matSum == target)
                        res++;
                }
            }
        }
    }

    return res;
}

int main()
{
    int target, row, col;
    printf("Enter the number of rows\n");
    scanf("%d", &row);
    printf("Enter the number of columns\n");
    scanf("%d", &col);
    printf("Enter the targeted sum\n");
    scanf("%d", &target);

    int **arr = (int **)calloc(row, sizeof(int*));
    for(int i = 0;i < row;i++) {
        arr[i] = (int *)calloc(col, sizeof(int));
    }
    arr[0][1] = 1;
    arr[1][0] = 1;
    arr[1][1] = 1;
    arr[1][2] = 1;
    arr[2][1] = 1;

    printf("The number of submatrices with their sum equal to %d are %d\n", target, numSubmatrixSumTarget(arr, row, &col, target));

    return 0;
}
/* Above code is for Array :
0 1 0
1 1 1
0 1 0
*/