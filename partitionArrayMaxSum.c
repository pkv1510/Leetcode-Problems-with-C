#include<stdio.h>
#include<stdlib.h>

int maxSumAfterPartitioning(int* arr, int n, int k) {
    int dp[502]={0};
    for(int i=1; i<=n; i++){
        int maxA=0, ans=0, k0=(i<k)?i:k, tmp;
        for(int j=1; j<=k0; j++){
            if ((tmp=arr[i-j])>maxA) maxA=tmp;
            if ((tmp=dp[i-j]+j*maxA)>ans) ans=tmp;
        }
        dp[i]=ans;
        printf("%d ", dp[i]);
    }
    return dp[n];
}

int main()
{
    int arr[]= {1,15,7,9,2,5,10};
    int size = sizeof(arr) / sizeof(int);

    printf("The maximum sum of the partitioned array is %d\n", maxSumAfterPartitioning(arr, size, 3));
    
    return 0;
}