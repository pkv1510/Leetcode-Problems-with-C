#include<stdio.h>
#include<stdlib.h>

int min2(int a, int b) {
    return a < b ? a : b;
}

int maxArea(int* height, int heightSize) {
    int right = heightSize - 1;
    int left = 0, max = 0;

    while(left <= right) {
        int currMax = min2(height[left], height[right]) * (right - left);
        if(height[left] < height[right])
            left++;
        else
            right--;

        if(currMax > max)
            max = currMax;
        
        printf("CurrMax is %d\n", currMax);
    }
    return max;
}

int main()
{
    // int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int arr[] = {2, 3, 4, 5, 18, 17, 6};
    int size = sizeof(arr) / sizeof(int);

    printf("The max area is %d \n", maxArea(arr, size));

    return 0;
}