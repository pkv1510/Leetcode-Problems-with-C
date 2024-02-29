#include<stdio.h>
#include<stdlib.h>

void printArray(int *ret, int size) {
    for(int i = 0;i < size;i++) {
        printf("%d ", ret[i]);
    }
    printf("\n");
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void fetchDigits(int *arr, int val, int *idx) {
    arr[*idx] = val;
    for(int i = val;i < 9;i++) {
        (*idx)++;
        arr[*idx] = arr[*idx - 1] * 10 + i + 1;
    }
    (*idx)++;
}

int* sequentialDigits(int low, int high, int* returnSize) {
    int *arr = (int *)malloc(sizeof(int) * 45);
    int idx = 0;

    for(int i = 1;i <= 9;i++) {
        fetchDigits(arr, i, &idx);
    }

    int k = 0;
    for(int i = 0;i < 45;i++) {
        if(arr[i] >= low && arr[i] <= high)
            (*returnSize)++;
    }
    int *res = (int *)calloc((*returnSize), sizeof(int));
    for(int i = 0;i < 45;i++) {
        if(arr[i] >= low && arr[i] <= high)
            res[k++] = arr[i];
    }
    free(arr);
    *returnSize = k;
    qsort(res, k, sizeof(int), compare);
    return res;
}

int main()
{
    int size;
    int *arr = sequentialDigits(89, 234, &size);
    printf("The array of all the sequential digits looks like :\n");
    printArray(arr, size);
    return 0;
}