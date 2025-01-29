#include<stdio.h>

int search(int* nums, int numsSize, int target) {
    int start = 0, end = numsSize-1;
    int mid = 0;

    while(start <= end) {
        mid = start + (end-start)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            start = mid+1;
        else 
            end = mid-1;
    }
    return -1;
}

int main() {
    int v[] = {-1,0,3,5,9,12};
    int target = 2;
    int size = *(&v + 1) -v;

    int idx = search(v,size, target);
    if(idx)
        printf("%d exists at index %d\n", target,idx);
    else
        printf("%d doesn't exist\n", target);
}