#include<stdio.h>
#include<stdlib.h>

int longestSubarray(int* nums, int numsSize) {
    int maxCount = 0, start = 0, count = 0, right = 0;
    while(right < numsSize) {
        if(!nums[right])
            count++;

        while(count > 1) {
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
    int nums[] = {0,1,1,1,0,1,1,0,1,1,0,1};
    int size = *(&nums + 1) - nums;

    printf("The maximum number of consecutive 1's after deleting a 0 is %d\n", longestSubarray(nums, size));

    return 0;
}
