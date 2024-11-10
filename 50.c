#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

double localPow(double x, int n) {
    if(n == 1) {
        return x;
    } else if(n % 2 == 0) {
        return localPow(x * x, n / 2);
    } else {
        return x * localPow(x * x, n / 2);
    }
}

double myPow(double x, int n) {
    if(n == 1) {
        return x;
    }
    if(!n)
        return 1;
    bool flag = false;
    if(n == INT_MIN) {
        flag = true;
        n = n + 1;
    }
    if(n < 0) {
        n = abs(n);
        x = 1 / x;
    }
    return (!flag) ? localPow(x, n) : x * localPow(x, n);
}

int main() {
    double num = 2.0000;
    int pow = 2;

    printf("The %d power of %lf is %lf\n", pow, num, myPow(num, pow));
    return 0;
}