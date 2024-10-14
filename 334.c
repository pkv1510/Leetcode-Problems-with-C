#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define INT_MAX 2147483647

// Method-1 Using O(n3) Time Complexity
bool increasingTriplet1(int* nums, int numsSize) {
    for(int i = 0;i < numsSize - 2;i++) {
        for(int j = i + 1;j < numsSize - 1;j++) {
            for(int k = j + 1;k < numsSize;k++) {
                if(nums[i] < nums[j]) {
                    if(nums[j] < nums[k]) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

//Method - 2 Using O(n) Time Complexity
bool increasingTriplet2(int* nums, int numsSize) {
    int left = INT_MAX, mid = INT_MAX;

    for(int i = 0;i < numsSize;i++) {
        if(nums[i] <= left)
            left = nums[i];
        else if(nums[i] <= mid)
            mid = nums[i];
        else
            return true;
    }
    return false;
}

int main() {
    //int nums[] = {1, 2, 3, 4, 5};
    //int nums[] = {5, 4, 3, 2, 1};
    //int nums[] = {0, 4, 2, 1, 0, -1, -3};
    //int nums[] = {20, 100, 10, 12, 5, 13};
    int nums[] = {1,5,0,4,1,3};
    int size = *(&nums + 1) - nums;

    if(increasingTriplet(nums, size))
        printf("The given array has increasing Triplet\n");
    else
        printf("The given array does not have increasing Triplet\n");

    return 0;
}
