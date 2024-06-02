#include<stdio.h>
#include<stdlib.h>

int countTriplets(int* arr, int arrSize) {
    int count = 0;
    for(int i = 0;i < arrSize;i++) {
        int val = arr[i];
        for(int j = i + 1;j < arrSize;j++) {
            val ^= arr[j];
            if(!val)
                count += (j - i);
        }
    }
    return count;
}

int main() {
    int arr[] = {2, 3, 1, 6, 7};
    int size = *(&arr + 1) - arr;

    printf("The number of resulting triplets are %d\n", countTriplets(arr, size));
    return 0;
}