#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int size) {
    for(int i = 0;i < size;i++)
        printf("%d ", arr[i]);
}

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* left = (int*)malloc(sizeof(int) * numsSize);
    int* right = (int*)malloc(sizeof(int) * numsSize);

    left[0] = nums[0];
    right[numsSize - 1] = nums[numsSize - 1];

    for(int i = 1;i < numsSize;i++) {
        left[i] = left[i - 1] * nums[i];
    }

    for(int i = numsSize - 2;i >= 0;i--) {
        right[i] = right[i + 1] * nums[i];
    }

    *returnSize = numsSize;
    int* ret = (int*)malloc(sizeof(int) * (*returnSize));
    for(int i = 0;i < *returnSize;i++) {
        if(!i)
            ret[i] = right[i + 1];
        else if(i == (*returnSize - 1))
            ret[i] = left[i - 1];
        else
            ret[i] = left[i - 1] * right[i + 1];
    }

    free(left);
    free(right);

    return ret;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int size = (*(&arr + 1) - arr);
    int retSize = 0;

    printf("The input array looks like :-\n");
    printArray(arr, size);

    printf("\nThe output array looks like :-\n");
    int *ret = productExceptSelf(arr, size, &retSize);
    printArray(ret, retSize);

    return 0;
}