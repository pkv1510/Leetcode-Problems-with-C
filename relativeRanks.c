#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

void printArray(int *arr, int size) {
    for(int i = 0;i < size;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void printStringArray(char **ret, int size) {
    for(int i = 0;i < size;i++) {
        printf("%s\n", ret[i]);
    }
}

const char* names[] = {"Gold Medal", "Silver Medal", "Bronze Medal"};

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    char **result = (char **)malloc(scoreSize * sizeof(char *));
    int array[scoreSize];

    for(int i = 0;i < scoreSize;i++)
        array[i] = score[i];
    qsort(array, scoreSize, sizeof(int), compare);

    for(int i = 0;i < scoreSize;i++) {
        for(int j = 0;j < scoreSize;j++) {
            if(score[i] == array[j]) {
                int pos = j;
                if (pos < 3) {
                    result[i] = strdup(names[pos]);
                } else {
                    result[i] = (char *)malloc(20);
                    if (result[i] == NULL)
                        exit(1);
                    sprintf(result[i], "%d", pos + 1);
                }
                break;
            }
        }
    }
    *returnSize = scoreSize;
    return result;
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int size = sizeof(arr)/sizeof(int);
    int retSize;

    printArray(arr, size);
    char **array = findRelativeRanks(arr, size, &retSize);
    printStringArray(array, retSize);
}