#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool uniqueOccurrences(int* arr, int arrSize) {
    int *ret = (int*)malloc(sizeof(int) * 2001);
    for (int i = 0; i < 2001; i++) {
        ret[i] = 0;
    }
    for(int i = 0;i < arrSize;i++) {
        ret[arr[i] + 1000]++;
    }

    bool isUnique = true;
    for(int i = 0;i < 2001;i++) {
        if (ret[i]) {
            for(int j = i + 1;j < 2001;j++) {
                if(ret[i] == ret[j]) {
                    isUnique = false;
                }
            }
            if(!isUnique)
                break;
        }
    }

    free(ret);
    return isUnique;
}

int main()
{
    int arr[] = {1, 2, 2, 6, 8, 6, 6, 6, 8, 8};
    int size = sizeof(arr) / sizeof(int);

    if(!uniqueOccurrences(arr, size))
        printf("The array doesn't have unique occurrences of every element\n");
    else
        printf("The array have unique occurrences of every element\n");

    return 0;
}