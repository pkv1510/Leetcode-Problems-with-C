#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void printBoolArray(bool* array, int size) {
    for(int i = 0;i < size; i++) {
        if(array[i]) {
            printf("%s ,", "true");
        } else {
            printf("%s ,", "false");
        }
    }
    printf("\n");
}

int findLargest(int* candies, int candiesSize) {
    int largest = candies[0];
    for(int i = 1;i< candiesSize;i++) {
        if(candies[i] >= largest)
            largest = candies[i];
    }
    return largest;
}

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    bool* ret = (bool*)malloc(sizeof(bool) * candiesSize);
    *returnSize = candiesSize;

    int largest = findLargest(candies, candiesSize);

    for(int i = 0;i < candiesSize;i++) {
        if((candies[i] + extraCandies) >= largest)
            ret[i] = true;
        else
            ret[i] = false;
    }

    return ret;
}

int main() {
    int candies[] = {2, 3, 5, 1, 3};
    int size = (*(&candies + 1) - candies);
    int extraCandies = 3;
    int retSize = 0;

    bool* ret = kidsWithCandies(candies, size, extraCandies, &retSize);
    printf("The retuirned bool array will look like :-");
    printBoolArray(ret, retSize);

    return 0;
}
