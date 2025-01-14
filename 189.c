#include<stdio.h>
#include<stdlib.h>

void printArray(int *nums, int size) {
    for(int i = 0;i < size;i++) {
        printf(" %d", nums[i]);
    }
    printf("\n");
}

/* Method - 1 
*  Time Complexity - O(n2)
*  Space Complexity - O(1)
*/
void rotateArray(int* nums, int size) {
    int end = size - 1;
    int temp = nums[end];

    while(end != 0) {
        nums[end] = nums[end - 1];
        end--;
    }
    nums[0] = temp;
}

void rotate1(int* nums, int numsSize, int k) {
    if(k == numsSize)
        return;

    k = k % numsSize;
    while(k != 0) {
        rotateArray(nums, numsSize);
        k--;
    }
}

/* Method - 2
*  Time Complexity - O(n)
*  Space complexity - O(n)
*/
void rotate2(int *nums, int numsSize, int k) {
    k = k % numsSize;
    int temp[numsSize];
    int j = 0;

    for(int i = numsSize - k; i < numsSize;i++) {
        temp[j++] = nums[i];
    }

    for(int i = 0;i < numsSize - k;i++) {
        temp[j++] = nums[i];
    }

    for(int i = 0;i < numsSize;i++) {
        nums[i] = temp[i];
    }
}

/* Method - 3
*  Time complexity - O(n)
*  Space Complexity - O(1)
*/
void reverseArray(int *nums, int start, int end) {
    int temp;

    while(start < end) {
        temp = nums[start];
        nums[start++] = nums[end];
        nums[end--] = temp;
    }
}

void rotate(int *nums, int numsSize, int k) {
    k = k % numsSize;

    if(k) {
        /* reverse the whole array */
        reverseArray(nums, 0, numsSize - 1);

        /* reverse the array upto the index k */
        reverseArray(nums, 0, k - 1);

        /* reverse the reset of the array */
        reverseArray(nums, k, numsSize - 1);
    }
}

int main() {
    int arr[] = {1, 2,3,4,5,6,7};
    int size = *(&arr + 1) - arr;

    printf("The original array is as: ");
    printArray(arr, size);

    int k = 3;
    rotate(arr, size, k);
    printf("The array after %d rotations is as: ", k);
    printArray(arr, size);

    return 0;
}