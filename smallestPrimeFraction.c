#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int size) {
    for(int i = 0;i < size;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void printFloatArray(float *arr, int size) {
    for(int i = 0;i < size;i++) {
        printf("%f ",arr[i]);
    }
    printf("\n");
}

int compare(const void* a, const void* b) {
    float diff = *(float*)a - *(float*)b;
    if(diff > 0) return 1;
    if(diff < 0) return -1;
    return 0;
}

int findSize(int size) {
    return ((size * (size - 1)) / 2);
}

int* kthSmallestPrimeFraction(int* arr, int arrSize, int k, int* returnSize) {
    int size = findSize(arrSize);
    float *temp = (float *)calloc(size, sizeof(float));
    int *res = (int *)calloc(2, sizeof(int));
    int index = 0;

    if(k == 1) {
        res[0] = arr[0];
        res[1] = arr[arrSize - 1];
        return res;
    }
    for (int i = 0;i < arrSize - 1;i++) {
        for (int j = i + 1;j < arrSize;j++) {
            temp[index++] = (float)arr[i] / (float)arr[j];
        }
    }
    printFloatArray(temp, size);

    *returnSize = 2;
    qsort(temp, size, sizeof(float), compare);
    printFloatArray(temp, size);

    for (int i = 0;i < arrSize - 1;i++) {
        for (int j = i + 1;j < arrSize;j++) {
            if(((float)arr[i] / (float)arr[j]) == temp[k - 1]) {
                res[0] = arr[i];
                res[1] = arr[j];
            }
        }
    }
    return res;
}

int main() {
    int arr[] = {1, 2, 3, 5};
    int size = sizeof(arr) / sizeof(int);
    int retSize;

    int *retArr = kthSmallestPrimeFraction(arr, size, 3, &retSize);

    printArray(retArr, retSize);

    return 0;
}

/*
int* kthSmallestPrimeFraction(int* arr, int arrSize, int k, int* returnSize){
    int *answer = malloc(sizeof(int) * 2);
    *returnSize = 2;
    double left = 0.0, right = 1.0; //代表分数数组两边的最大值
    int i = 0;

    while(true) {
        double mid = (left + right) / 2;    //二分法,其实随意找出一个值，小于这个分数值前面刚好有k-1个数
        int i = -1, count = 0;  // 这里i从-1开始取，非常重要
        /* 记录最大的分数 
        int min = 0, max = 1;
    
        for(int j = 1; j < arrSize; j++) {  //j从1开始，每次都需要
            while((double)arr[i + 1] / arr[j] < mid) {
                i++;
                if (arr[i] * max > arr[j] * min) {  //每次记录最大的分数的分子和分母的值,其实就是arr[i]/arr[j] > min/max
                    min = arr[i];
                    max = arr[j];
                }
            }
            count += i + 1;     //统计所有小于mid的分数的个数
        }
        if(count == k) {
            answer[0] = min;
            answer[1] = max;
            return answer;
        }
        if(count < k) { //说明范围小了
            left = mid;
        } else {
            right = mid;
        }
    }

    return answer;
}
*/