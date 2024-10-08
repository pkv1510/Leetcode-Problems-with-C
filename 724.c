#include<stdio.h>
#include<stdlib.h>

int pivotIndex(int* nums, int numsSize) {
    int *left = (int*)malloc(sizeof(int) * numsSize);
    int *right = (int*)malloc(sizeof(int) * numsSize);
    left[0] = 0,right[numsSize - 1] = 0;
    for(int i = 0, j = numsSize - 1;i < numsSize - 1, j > 0;i++, j--) {
        left[i + 1] = left[i] + nums[i];
        right[j - 1] = right[j] + nums[j]; 
    }

    for(int i = 0;i < numsSize;i++) {
        if(left[i] == right[i]) {
            free(left);
            free(right);
            return i;
        }
    }
    free(left);
    free(right);
    
    return -1;
}

int main() {
    int nums[] = {1,7,3,6,5,6};
    int size = *(&nums + 1) - nums;

    printf("The pivot index from where the sum to the start is equal to sum to end is %d\n", pivotIndex(nums, size));
}
