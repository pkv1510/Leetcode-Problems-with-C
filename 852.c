#include<stdio.h>

int peakIndexInMountainArray(int* arr, int arrSize) {
    int start = 0, end = arrSize-1;
    int mid = 0;

    while(start <= end) {
        mid = start + (end-start)/2;
        if(mid == 0)
            return end;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
            return mid;
        else if(arr[mid] < arr[mid-1])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int main() {
    int arr[] = {3,5,3,2,1,0};
    int size = *(&arr + 1) - arr;

    printf("The Peak Index is at %d\n", peakIndexInMountainArray(arr,size));

    return 0;
}