#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool isPalindrome1(int x) {
    int s = x;
    int res = 0;

    while (x != 0) {
        int temp = x % 10;
        res = res * 10 + temp;
        if(res < 0)
            return false;
        x = x / 10;
    }

    return (s == res);
}

bool isPalindrome(int x) {
    int s;

    if(x < 0)
        return false;
    else if(x >= 0 && x < 10)
        return true;
    else
        s = x;

    int size = 0;
    while (s > 0) {
        s = s / 10;
        size++;
    }

    int *arr = (int*)malloc(sizeof(int) * size);

    for(int i = 0;i < size;i++) {
        arr[i] = x % 10;
        x = x / 10;
    }
    int mid;
    if(size % 2 == 0)
    {
        int end = size - 1;
        mid = size / 2;
        for(int i = 0;i < mid;i++) {
            if(arr[i] == arr[end]) {
                end--;
            }
            else {
                return false;
            }
        }
        return true;
    }
    else {
        mid = (size - 1) / 2;
        int right = mid, left = mid;
        for(int i = 0;i <= mid;i++) {
            if((arr[right] == arr[left]) && ((right < size) && (left >= 0))) {
                right++;
                left--;
            }
            else {
                return false;
            }
        }
        return true;
    }
}

int main()
{
    int x = 1000110001;

    if(isPalindrome(x))
        printf("The number is palindrome \n");
    else
        printf("The number is not palindrome\n");

    return 0;
}