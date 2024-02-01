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

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    for(int i = 0;i < numsSize;i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    int **res = (int **)malloc(sizeof(int) * numsSize * numsSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * numsSize * numsSize);
    *returnSize = 0;

    for(int j = 0;j < numsSize - 3;j++) {
        if(j > 0 && (nums[j] == nums[j - 1]))
            continue;
        for(int i = j + 1;i < numsSize - 2;i++) {
            if(i > (j + 1) && (nums[i] == nums[i - 1]))
                continue;

            int left = i + 1;
            int right = numsSize - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right] + nums[j];
                if(sum == target) {
                    res[*returnSize] = (int *)malloc(sizeof(int) * 4) ;
                    res[*returnSize][0] = nums[j];
                    res[*returnSize][1] = nums[i];
                    res[*returnSize][2] = nums[left];
                    res[*returnSize][3] = nums[right];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                } else if(sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return res;
}

int main()
{
    int arr[] = {-3,-1,0,2,4,5};
    //int arr[] = {1,0,-1,0,-2,2};
    int retSize;
    int size = sizeof(arr) / sizeof(int);
    int *retColumnSize;
    int target = 2;
    
    int **res = fourSum(arr, size, target, &retSize, &retColumnSize);
    printf("The array of all the 4Sums whose sum is 0 looks like :\n");
    print2D_Array(res, retSize, 4);

    return 0;
}