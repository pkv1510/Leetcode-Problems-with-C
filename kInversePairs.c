#include<stdio.h>
#include<stdlib.h>

void print_2D(long long **arr, int row, int col) {
    for(int i = 0;i < row;i++) {
        for(int j = 0;j < col;j++) {
            printf("%lld ", arr[i][j]);
        }
        printf("\n");
    }
}

int kInversePairs(int n, int k) {
    if (k == 0) {
        return 1;
    }
    if (k == 1) {
        return n - 1;
    }

    long long **arr = (long long **)malloc(sizeof(long long *) * 2);
    for (int i = 0; i < 2; i++) {
        arr[i] = (long long *)calloc((k + 1), sizeof(long long));
    }

    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[1][0] = 1;

    int j = 0, last = 0, curr = 0;
    for (int i = 3; i <= n; i++) {
        curr = i % 2;
        int k_max = ((i - 1) * i) / 2;
        arr[curr][1] = i - 1;
        int min = k < i ? k + 1 : i;
        arr[curr][2] = arr[last][0] + arr[last][1] + arr[last][2];
        for (j = 3; j < min; j++) {
            arr[curr][j] = (arr[curr][j - 1] + arr[last][j]) % 1000000007;
        }
        int count = 0;
        for (; j <= k; j++) {
            if (j >= k_max) {
                arr[curr][k_max] = 1;
                break;
            }
            arr[curr][j] = (arr[curr][j - 1] + arr[last][j] - arr[last][count]) % 1000000007;
            count++;
        }
        last = curr;
    }

    print_2D(arr, 2, k+1);
    int ans = arr[curr][k] >= 0 ? arr[curr][k] : arr[curr][k] + 1000000007;
    free(arr[0]);
    free(arr[1]);
    free(arr);
    return ans;
}

int main()
{
    int num1, num2;

    printf("Enter the value of n\n");
    scanf("%d", &num1);
    printf("Enter the value of k\n");
    scanf("%d", &num2);

    printf("The maximum number of inverse array pairs are %d\n", kInversePairs(num1, num2));

    return 0;
}