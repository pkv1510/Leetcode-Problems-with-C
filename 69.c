#include<stdio.h>

int mySqrt(int x) {
    int start = 0, end = x;
    int mid = 0;

    while(start <= end) {
        int mid = start + (end-start)/2;
        long long m = (long long)mid*mid;
        if(m == x)
            return mid;
        else if(m > x)
            end = mid -1;
        else
            start = mid +1;
    }
    return end;
}

int main() {
    int x = 12;
    printf("The sqaure root of %d is %d\n", x, mySqrt(x));

    return 0;
}