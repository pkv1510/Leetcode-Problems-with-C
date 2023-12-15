#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int size) {
    for(int i = 0;i < size;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

/*
//Code Sample (Runtime: 1ms)

struct intPair {
    int x;
    int order;
};

int compare(const void *a, const void *b) {
    struct intPair *p = (struct intPair *) a;
    struct intPair *q = (struct intPair *) b;
    return p->x - q->x;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j, *output;
    output = malloc(2 * sizeof(int));
    *returnSize = 2;
    struct intPair *arr = malloc(numsSize * sizeof(struct intPair));
    for (i = 0; i < numsSize; ++i) {
        arr[i].x = nums[i];
        arr[i].order = i;
    }
    qsort(arr, numsSize, sizeof(struct intPair), compare);
    i = 0;
    j = numsSize - 1;
    while (arr[i].x + arr[j].x != target) {
        while (arr[i].x + arr[j].x < target) {
            ++i;
        }
        while (arr[i].x + arr[j].x > target) {
            --j;
        }
    }
    output[0] = arr[i].order;
    output[1] = arr[j].order;
    free(arr);
    return output;
}
*/

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *ret = (int*)malloc(2 * sizeof(int));

    for(int i = 0;i < numsSize;i++) {
        for(int j = i + 1;j < numsSize;j++) {
            if(nums[i] + nums[j] == target) {
                ret[0] = i + 1;
                ret[1] = j + 1;

                *returnSize = 2;
                return ret;
            }
        }
    }

    return NULL;
}

int main() {
    //int arr[] = {2, 7, 11, 15};
    int arr[] = {3, 2, 4};
    int size = sizeof(arr)/sizeof(int);
    int target, *targetArray, targetArraySize;

    printf("Enter the target value \n");
    scanf("%d", &target);

    targetArray = twoSum(arr, size, target, &targetArraySize);
    printArray(targetArray, targetArraySize);

    free(targetArray);

    return 0;
}