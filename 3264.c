#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void printArray(int* nums, int size) {
    for(int i = 0;i < size;i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int findSmallest(int *nums, int size) {
    int smallest = INT_MAX, index = 0;
    for(int i = 0;i < size;i++) {
        if(smallest > nums[i]) {
            smallest = nums[i];
            index = i;
        }
    }
    return index;
}

int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {
    *returnSize = numsSize;

    int index = 0;
    while(k) {
        index = findSmallest(nums, numsSize);
        nums[index] = multiplier * nums[index];
        k--;
    }

    return nums;
}

int main() {
    int nums[] = {2,1,3,5,6};
    int size = *(&nums + 1) - nums;
    int k = 5, multiplier = 2;
    int returnSize;

    printf("The original array is as : ");
    printArray(nums, size);

    int *ret = getFinalState(nums, size, k, multiplier, &returnSize);

    printf("The new Array is as : ");
    printArray(ret, returnSize);

    return 0;
}