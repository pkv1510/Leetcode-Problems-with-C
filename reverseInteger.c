#include<stdio.h>
#include<stdlib.h>

#define MAX 2147483647
#define MIN (-2147483648)

int reverse(int x){
    long int s = 0;
    int temp = 0;

    while(x != 0) {
        temp = x % 10;
        if((s * 10) <= MAX && (s * 10) >= MIN) {
            s = s * 10 + temp;
        }
        else {
            return 0;
        }
        x = x / 10;
    }
    return (int)s;
}

int main()
{
    //int val = 1534236469;
    int val = -2147483648;

    printf("The reverse of the integer is %d\n", reverse(val));
    return 0;
}