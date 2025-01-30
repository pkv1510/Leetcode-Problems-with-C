#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int search(int* nums, int numsSize, int target, bool flag) {
    int start = 0, end = numsSize-1;
    int mid = 0;
    int idx = -1;

    while(start <= end) {
        mid = start + (end-start)/2;
        if(nums[mid] == target){
            idx = mid;
            if(flag)
                end = mid - 1;
            else
                start = mid + 1;
        }
        else if(nums[mid] < target)
            start = mid+1;
        else 
            end = mid-1;
    }
    return idx;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *ret = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    ret[0] = search(nums, numsSize, target, true);
    ret[1] = search(nums, numsSize, target, false);
    return ret;
}

int main() {
    int v[] = {-1,0,3,5,9,12};
    int target = 12;
    int size = *(&v + 1) -v;
    int returnSize;

    int *ret = searchRange(v,size, target, &returnSize);
    printf("%d and %d\n", ret[0], ret[1]);
}