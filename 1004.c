#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int longestOnes1(int* nums, int numsSize, int k) {
    int maxCount = INT_MIN;
    for(int i = 0;i < numsSize;i++) {
        int count = 0, max = 0;
        for(int j = i;j < numsSize;j++) {
            printf("%d\n", nums[j]);
            if(!nums[j])
                count++;
            else
                max++;
            if(count > k) {
                max = max + count - 1;
                break;
            }
        }
        if(max > maxCount)
            maxCount = max;
    }
    return maxCount;
}

int longestOnes(int* nums, int numsSize, int k) {
    int maxCount = 0, start = 0, count = 0, right = 0;
    while(right < numsSize) {
        if(!nums[right])
            count++;

        while(count > k) {
            if(!nums[start])
                count--;

            start++;
        }
        if((right - start + 1) > maxCount)
            maxCount = right - start + 1;

        right++;

    }
    return maxCount;
}

int main() {
    //int nums[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int nums[] = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int size = *(&nums + 1) - nums;
    int k = 3;

    printf("The maximum number of consecutive 1's after flipping atmost %d 0's is %d\n", k, longestOnes(nums, size, k));

    return 0;
}
