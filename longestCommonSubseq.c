#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max2(int a, int b) {
    return (a > b) ? a : b;
}

int longestCommonSubsequence(char* text1, char* text2) {
    const int sLen = strlen(text1);
    const int pLen = strlen(text2);
    int arr[pLen + 1][sLen + 1];
    for(int i = 0;i <= pLen;i++) {
        for(int j = 0;j <= sLen;j++) {
            arr[i][j] = 0;
        }
    }
    
    for(int i = 1;i <= pLen;i++) {
        for(int j = 1;j <= sLen;j++) {
            if(text1[j - 1] == text2[i - 1])
                arr[i][j] = arr[i - 1][j - 1] + 1;
            else
                arr[i][j] = max2(arr[i][j - 1], arr[i - 1][j]);
        }
    }
    return arr[pLen][sLen];
}

int main()
{
    char *str1 = "abcde";
    char *str2 = "ace";

    printf("The longest common subsequence in the string can be of %d\n", longestCommonSubsequence(str1, str2));

    return 0;
}