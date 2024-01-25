#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

bool isMatch(char *s, char *p) {
    int sLen = strlen(s);
    int pLen = strlen(p);
    bool dp[sLen + 1][pLen + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;

    for (int j = 1; j <= pLen; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    for (int i = 1; i <= sLen; i++) {
        for (int j = 1; j <= pLen; j++) {
            if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (p[j - 2] == s[i - 1] || p[j - 2] == '.'));
            }
        }
    }

    return dp[sLen][pLen];
}

bool isMatch1(char* s, char* p) 
{
    if (!p[0]) {
        return !s[0] ? true : false;
    } else if (p[1] == '*') {
        while (s[0] && (s[0] == p[0] || p[0] == '.'))
        {
            if (isMatch1(s++, p+2))
                return true;
        }
        return isMatch1(s, p+2);
    }
    return (s[0] && (s[0] == p[0] || p[0] == '.')) ? isMatch1(s+1, p+1) : false;
}

int main()
{
    // char *str1 = "ab";
    // char *str2 = "ab*";
    // char *str1 = "aab";
    // char *str2 = "c*a*b";
    // char *str1 = "mississippi";
    // char *str2 = "mis*is*ip*.";
    char *str1 = "aaa";
    char *str2 = "aaaa";

    if(isMatch(str1, str2))
        printf("The string str2 is the regular expression of str2\n");
    else
        printf("The string str2 is not a regular expression of str1\n");

    return 0;
}