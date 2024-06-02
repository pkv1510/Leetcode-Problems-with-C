#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int size) {
    for(int i = 0;i < size;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int specialArray(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    printArray(nums, numsSize);

    if(nums[0] >= numsSize)
        return nums[0];
    
    if (!nums[0])
        return -1;

    for(int i = 1;i <= numsSize;i++) {
        if((nums[numsSize - i] >= i) && ((numsSize - i - 1) < 0 || (nums[numsSize - i - 1] < i)))
            return i;
    }

    return -1;
}

int specialArray1(int *nums, int size) {
    int temp[1001];
    for(int i = 0;i < size;i++)
        temp[nums[i]]++;

    int total = size;
    for(int i = 0;i < 1001;i++) {
        if(i == total)
            return i;
        else 
            total -= temp[i];
    }
    return -1;
}

int main() {
    //int arr[] = {3, 6, 7, 7, 0};
    //int arr[] = {0, 0};
    int arr[] = {0,5,0,1,8,3,0,1};
    int size = sizeof(arr) / sizeof(int);

    printArray(arr, size);

    int ret = specialArray(arr, size);

    if(ret == -1)
        printf("The given array is not special\n");
    else
        printf("The Array is special with val %d\n", ret);

    return 0;
}