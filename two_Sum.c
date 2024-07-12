#include<stdio.h>
#include<stdlib.h>
#include "uthash.h"

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

int* twoSum1(int* nums, int numsSize, int target, int* returnSize) {
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
/*
* For this method one extra file will be required
 struct hashTable {
        int key; 
        int value; 
        UT_hash_handle hh;
} *hashTable = NULL, *item;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        HASH_FIND_INT(hashTable, &complement, item);
        if (item) {
            int* result = malloc(sizeof(int) * 2);
            result[0] = item->value;
            result[1] = i;
            *returnSize = 2;
            HASH_CLEAR(hh, hashTable);
            return result;
        }
        item = malloc(sizeof(struct hashTable));
        item->key = nums[i];
        item->value = i;
        HASH_ADD_INT(hashTable, key, item);
    }

    *returnSize = 0;
    HASH_CLEAR(hh, hashTable);
    return NULL;
}
*/

struct ht{
    int index;
    int value;
};

struct ht htable[5];

void init_hash_table() {
    for(int i = 0;i < 5;i++) {
        htable[i].value = -1;
        htable[i].index = i;
    }
}

void update_hash_table(int *nums, int size) {
    for(int i = 0;i < size;i++) {
        htable[nums[i]].value = i;
    }
}

int lookup_hash_table(int val) {
    return (htable[val].value != -1) ? htable[val].value : 0;
}

void print_hash_table() {
    for(int i = 0;i < 5;i++) {
        printf("\t%d\t%d\n", htable[i].index, htable[i].value);
    }
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int index = lookup_hash_table(complement);
        if(index) {
            int* ret = malloc(sizeof(int) * 2);
            ret[0] = i;
            ret[1] = index;
            *returnSize = 2;
            return ret;
        }
    }
    *returnSize = 0;
    return NULL;
}

int main() {
    //int arr[] = {2, 7, 11, 15};
    int arr[] = {3, 2, 4};
    int size = sizeof(arr)/sizeof(int);
    int target, *targetArray, targetArraySize;

    init_hash_table();
    update_hash_table(arr, size);
    print_hash_table();

    printf("Enter the target value \n");
    scanf("%d", &target);

    targetArray = twoSum(arr, size, target, &targetArraySize);
    printArray(targetArray, targetArraySize);

    return 0;
}