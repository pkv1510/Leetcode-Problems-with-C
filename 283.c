#include<stdio.h>
#include<stdlib.h>

void printArray(int *nums, int size) {
    for(int i = 0;i < size;i++) {
        printf(" %d", nums[i]);
    }
    printf("\n");
}

void moveZeroes(int *nums, int numsSize) {
    int temp;
    for(int i = 0;i < numsSize;i++) {
        for(int j = 0;j < numsSize;j++) {
            if(!nums[j]) {
                temp = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {0,1,0,3,12};
    int size = *(&arr + 1) - arr;

    printf("The original array is as: ");
    printArray(arr, size);

    moveZeroes(arr, size);
    printf("The array after moving all the zeroes at the end is as: ");
    printArray(arr, size);

    return 0;
}
