#include<stdio.h>
#include<stdlib.h>

void print2D_Array(int** arr, int row, int col)
{
  int i,j;
  for (i=0; i < row; i++) {
    for (j=0; j < col; j++) 
        printf("%d ", arr[i][j]);
    printf("\n");
  }
  printf("\n");
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);

    int **res = (int **)malloc(sizeof(int) * numsSize * numsSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * numsSize * numsSize);
    *returnSize = 0;

    for(int i = 0;i < numsSize - 2;i++) {
        if(i && (nums[i] == nums[i - 1]))
            continue;

        int left = i + 1;
        int right = numsSize - 1;
        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0) {
                res[*returnSize] = (int *)malloc(sizeof(int) * 3) ;
                res[*returnSize][0] = nums[i];
                res[*returnSize][1] = nums[left];
                res[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            } else if(sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return res;
}

int main()
{
    //int arr[] = {-1, 0, 1, 2, -1, -4};
    int arr[] = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    int retSize;
    int size = sizeof(arr) / sizeof(int);
    int *retColumnSize;
    
    int **res = threeSum(arr, size, &retSize, &retColumnSize);
    printf("The array of all the 3Sums whose sum is 0 looks like :\n");
    print2D_Array(res, retSize, 3);

    return 0;
}