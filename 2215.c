#include<stdio.h>
#include<stdlib.h>

void printDoubleArray(int** arr, int row, int col)
{
  int i,j;
  for (i=0; i < row; i++) {
    for (j=0; j < col; j++) 
        printf("%d ", arr[i][j]);
    printf("\n");
  }
  printf("\n");
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {
    int hash1[2001] = {0};
    int hash2[2001] = {0};
    int j = 0, k = 0;

    int **ret = (int **)malloc(sizeof(int*) * 2);

    ret[0] = (int *)malloc(sizeof(int) * nums1Size);
    ret[1] = (int *)malloc(sizeof(int) * nums1Size);
    *returnColumnSizes = (int *)malloc(2 * sizeof(int));

    for(int i = 0;i < nums1Size;i++) {
        hash1[nums1[i] + 1000] = 1;
    }

    for(int i = 0;i < nums2Size;i++) {
        hash2[nums2[i] + 1000] = 1;
    }

    for(int i = 0;i <= 2000;i++) {
        if(hash1[i] == hash2[i]) {
            continue;
        } else if (hash1[i]) {
            ret[0][j++] = i - 1000;
        } else {
            ret[1][k++] = i - 1000;
        }
    }
    *returnSize = 2;

    (*returnColumnSizes)[0] = j;
    (*returnColumnSizes)[1] = k;
    return ret;
}

int main() {
    int nums1[] = {1,2,3};
    int size1 = *(&nums1 + 1) - nums1;
    int nums2[] = {2,4,6};
    int size2 = *(&nums2 + 1) - nums2;
    int returnSize, colSize;
    int *returnColSize = &colSize;
    int **ret;

    ret = findDifference(nums1, size1, nums2, size2, &returnSize, &returnColSize);

    printf("The difference array of the two given array is :-\n");
    printDoubleArray(ret, 2, 2);

    return 0;
}
