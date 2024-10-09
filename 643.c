#include<stdio.h>
#include<stdlib.h>

#define INT_MIN (-2147483648)

// Method - 1 Using O(n2) Time Complexity
double findMaxAverage1(int* nums, int numsSize, int k) {
    int sum = 0;
    double max = 0;

    for(int i = 0;i < (numsSize - k + 1);i++) {
        sum = 0;
        for(int j = i;j < (i + k);j++) {
            sum += nums[j];
        }
        if(max < (double)sum / k) {
            max = (double)sum / k;
        }
    }

    return max;
}

//Method - 2 Using O(n) Time Complexity
double findMaxAverage(int* nums, int numsSize, int k) {
    int left = 0, right = k;
    double sum = 0;
    double maxAvg = INT_MIN;
    
    for(int j = 0;j < k;j++) {
        sum += nums[j];
    }
    maxAvg = (double)sum / k;

    while(right < numsSize) {
        sum -= nums[left++];
        sum += nums[right++];
        if(maxAvg < sum / k) {
            maxAvg = sum / k;
        }
    }

    return maxAvg;
}

int main() {
    int arr[] = {1, 12, -5, -6, 50, 3};
    int size = *(&arr + 1) - arr;
    int k = 4;

    printf("The maximum average of any subarray of %d length is %lf\n", k, findMaxAverage(arr, size, k));

    return 0;
}