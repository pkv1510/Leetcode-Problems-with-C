#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int size)
{
    for (int i = 0;i < size;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int numsScore = 0;
    for(int i = 0;i < numsSize;i++)
        numsScore ^= nums[i];
    
    int first = 0, second = 0;
    unsigned int bitPos = numsScore & -(unsigned int)numsScore;
    
    for(int i = 0;i < numsSize;i++) {
        if((nums[i] & bitPos) != 0)
            first ^= nums[i];
        else
            second ^= nums[i];
    }
    int *ret = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    ret[0] = first;
    ret[1] = second;

    return ret;
}

int main() {
    int arr[] = {1,2,1,3,2,5};
    int size = *(&arr + 1) - arr;
    int retSize = 0;

    printArray(arr, size);

    int *ret = singleNumber(arr, size, &retSize);
    printArray(ret, 2);
    return 0;
}