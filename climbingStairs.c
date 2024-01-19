#include<stdio.h>

int climbStairs(int n) {
    int prev = 1;
    int curr = 2;
    int ways = 0;

    if(n == 1) {
        return prev;
    }
    else if(n == 2) {
        return curr;
    }
    else {
        for(int i = 3;i <= n;i++) {
            ways = prev + curr;
            prev = curr;
            curr = ways;
        }
    }

    return ways;
}
int main()
{
    int num;
    printf("Enter the total number of stairs\n");
    scanf("%d", &num);

    printf("The %d stairs can be climed in %d ways\n", num, climbStairs(num));

    return 0;
}