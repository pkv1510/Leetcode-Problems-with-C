#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maxOperations(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), compare);
    int i = 0, j = numsSize - 1, count = 0;

    while(i < j) {
        if(nums[i] + nums[j] < k) {
            i++;
        } else if(nums[i] + nums[j] > k) {
            j--;
        } else {
            i++;
            j--;
            count++;
        }
    }

    return count;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int size = *(&arr + 1) - arr;
    int target = 5;

    printf("The array has %d number of %d-sum pairs\n", maxOperations(arr, size, target), target);

    return 0;
}
