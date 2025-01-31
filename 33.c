#include<stdio.h>

int search(int* nums,int numsSize, int target) {
    int start = 0, end = numsSize-1;
    int mid = 0;
    int idx = -1;

    if(nums[0] == target)
        return  0;
    if(end == 1) {
        if(nums[0] == target) return 0;
        else if(nums[1] == target) return 1;
        else return -1;
    }

    while(start <= end) {
        mid = start + (end-start)/2;
        if(mid == 0)
            start = mid+1;
        else if(mid == numsSize-1)
            end = mid - 1;
        else if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
            idx = mid+1;
            break;
        }
        else if(nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]) {
            idx = mid;
            break;
        }
        else if(nums[mid] < nums[start])
            end = mid - 1;
        else
            start = mid + 1;
    }

    if(idx == -1) {
        start = 0;
        end = numsSize-1;
        while(start<=end){
            mid = start +(end-start)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                end = mid-1;
            else
                start = mid+1;
        }
    }
    else if(nums[0] < target){
        start = 0;
        end = idx -1;
    }
    else {
        start = idx;
        end = numsSize-1;
    }

    while(start<=end){
        mid = start +(end-start)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            end = mid-1;
        else
            start = mid+1;
    }
    return -1;
}

int main() {
    int arr[] = {5,1,2,3,4};
    int size = *(&arr + 1) - arr;
    int target = 4;
    printf("The target %d is at index %d\n", target,search(arr,size, target));
}