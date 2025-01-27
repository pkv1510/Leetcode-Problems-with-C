#include<stdio.h>
#include<stdlib.h>

int id = 0;

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void Helper(int** res, int *candidates, int size,int idx, int target, int* ret, int *retSize, int** returnColumnSizes, int count) {
    if(target == 0) {
        res[id] = (int*)malloc((*retSize) * sizeof(int));
        (*returnColumnSizes)[id] = 0;
        for(int i = 0;i < *retSize;i++) {
            res[id][i] = ret[i];
            (*returnColumnSizes)[id] += 1;
        }
        id++;
        return;
    }
    if(target < 0) return;
    for(int i = idx;i < size;i++) {
        if(i > idx && candidates[i] == candidates[i-1])
            i++;
        ret[count] = candidates[i];
        (*retSize)++;
        Helper(res, candidates, size,i+1, target-candidates[i], ret, retSize, returnColumnSizes, count+1);
        (*retSize)--;
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int **res = (int**)malloc(200*sizeof(int*));
    *returnColumnSizes = (int*)malloc(200*sizeof(int));
    *returnSize = 0;

    int ret[candidatesSize];
    int retSize = 0;
    id=0;

    qsort(candidates, candidatesSize, sizeof(int), compare);

    Helper(res, candidates, candidatesSize,0, target, ret, &retSize, returnColumnSizes, 0);
    *returnSize = id;

    return res;
}

int main() {
    int candidates[] = {1,1};
    //int candidates[] = {10,1,2,7,6,1,5};
    int size = *(&candidates + 1) - candidates;

    int target = 1;
    int returnSize = 0;
    int* returnColSize = NULL;

    int **ans = combinationSum(candidates, size, target, &returnSize, &returnColSize);
    for (int i = 0; i < returnSize; i++) {
        printf("{ ");
        for (int j = 0; j < returnColSize[i]; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("}\n");
    }
    return 0;
}