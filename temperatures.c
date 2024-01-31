#include<stdio.h>
#include<stdlib.h>

int* dailyTemperatures1(int* temperatures, int temperaturesSize, int* returnSize) {
    int* result = (int*)malloc(temperaturesSize * sizeof(int));
    *returnSize = temperaturesSize;
    result[temperaturesSize - 1] = 0;

    for(int i = 0;i < temperaturesSize - 1;i++) {
        result[i] = 0;
        for(int j = i + 1;j < temperaturesSize;j++) {
            if(temperatures[j] > temperatures[i]) {
                result[i] = j - i;
                break;
            }
        }
    }
    return result;
}

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* result = (int*)malloc(temperaturesSize * sizeof(int));
    *returnSize = temperaturesSize;

    int *stack = (int *)calloc(temperaturesSize, sizeof(int));
    int top = -1;

    for(int i = temperaturesSize - 1;i >= 0;i--) {
        while(top != -1 && temperatures[i] >= temperatures[stack[top]])
            top--;

        result[i] = (top == -1) ? 0 : stack[top] -  i;
        stack[++top] = i;
    }

    free(stack);

    return result;
}

int main()
{
    int arr[] = {73,74,75,71,69,72,76,73};
    int size = sizeof(arr) / sizeof(int);
    int returnSize;

    int *res = dailyTemperatures(arr, size, &returnSize);
    for(int i = 0;i < size;i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}