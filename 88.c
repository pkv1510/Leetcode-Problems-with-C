#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int size) {
	for(int i = 0;i < size;i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int j = 0;
    for(int i = m;i < (m + n);i++) {
        nums1[i] = nums2[j++];
    }
    printArray(nums1, 9);
    qsort(nums1, (m + n), sizeof(int), compare);
}

int main() {
    int arr[] = {1, 2, 3,3, 4, 0 , 0 ,0, 0};
    int size1 = *(&arr + 1) - arr;
    int arr2[] = {1,2 ,3 ,4};
    int size2 = *(&arr2 + 1) - arr2;
    
    merge(arr, size1, 5, arr2, size2, 4);

    printArray(arr, size1);

    return 0;
}
