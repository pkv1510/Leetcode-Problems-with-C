#include <stdio.h>
#include <stdlib.h>

int id = 0;

int power(int num, int pow) {
    if (pow == 0) return 1;
    return num * power(num, pow - 1);
}

void helper(int** ans, int* nums, int size, int idx, int* ret, int* retSize, int** returnColumnSizes) {
    if (idx == size) {
        ans[id] = (int*)malloc((*retSize) * sizeof(int));
        for (int i = 0; i < *retSize; i++) {
            ans[id][i] = ret[i];
        }
        (*returnColumnSizes)[id] = *retSize;
        id++;
        return;
    }
    helper(ans, nums, size, idx + 1, ret, retSize, returnColumnSizes);

    ret[(*retSize)++] = nums[idx];
    helper(ans, nums, size, idx + 1, ret, retSize, returnColumnSizes);
    (*retSize)--;
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int size = power(2, numsSize);
    int** ans = (int**)malloc(size * sizeof(int*));
    *returnColumnSizes = (int*)malloc(size * sizeof(int));
    *returnSize = size;

    int ret[numsSize];
    int retSize = 0;
    id=0;
    helper(ans, nums, numsSize, 0, ret, &retSize, returnColumnSizes);

    return ans;
}

int main() {
    int arr[] = {1,2,3};
    int size = sizeof(arr) / sizeof(arr[0]);

    int retSize = 0;
    int* returnColSize = NULL;

    int** ans = subsets(arr, size, &retSize, &returnColSize);

    for (int i = 0; i < retSize; i++) {
        printf("{ ");
        for (int j = 0; j < returnColSize[i]; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("}\n");
    }

    for (int i = 0; i < retSize; i++) {
        free(ans[i]);
    }
    free(ans);
    free(returnColSize);

    return 0;
}
