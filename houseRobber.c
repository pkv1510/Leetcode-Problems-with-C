#include<stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int rob(int* nums, int numsSize) {
    int sums[110], i = 0;

    sums[0] = nums[0];
    sums[1] = nums[1];
    sums[2] = nums[0] + nums[2];

    for(i = 3;i < (numsSize + 2);i++) {
        sums[i] = max(sums[i - 2], sums[i - 3]);
        if(i < numsSize)
            sums[i] += nums[i];
    }
    return max(sums[i - 1], sums[i - 2]);
}

int main()
{
    int arr[] = {2, 3, 4, 5, 18, 17, 6};
    int size = sizeof(arr) / sizeof(int);

    printf("The max loot in a night can be %d \n", rob(arr, size));
    return 0;
}