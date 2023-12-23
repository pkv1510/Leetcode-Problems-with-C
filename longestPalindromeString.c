#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Method - 1
int expandAroundCenter(char* s, int left, int right) {
    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

char* longestPalindrome1(char* s) {
    if (s == NULL || strlen(s) == 0) {
        return NULL;
    }

    int start = 0, end = 0;

    for (int i = 0; i < strlen(s); i++) {
        // Check palindromes with odd length
        int len1 = expandAroundCenter(s, i, i);

        // Check palindromes with even length
        int len2 = expandAroundCenter(s, i, i + 1);

        // Find the maximum length palindrome centered at position i
        int len = len1 > len2 ? len1 : len2;

        // Update start and end indices if a longer palindrome is found
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

    // Allocate memory for the result and copy the longest palindrome
    char* result = (char*)malloc((end - start + 2) * sizeof(char));
    strncpy(result, s + start, end - start + 1);
    result[end - start + 1] = '\0';

    return result;
}
//Method - 2 (Reduced Time complexity)
char* longestPalindrome(char* s) {
    if (s == NULL || strlen(s) == 0) {
        return NULL;
    }

    int n = strlen(s);
    int len = 2 * n + 1;
    //t is an array of characters where every character is divided by a "#"
    char* t = (char*)malloc(len * sizeof(char)); 
    //p is used as an array of lengths with "#" as a mirror in the palindrome string
    int* p = (int*)malloc(len * sizeof(int)); 
    int center = 0, right = 0;

    for (int i = 0; i < n; i++) {
        t[2 * i] = '#';
        t[2 * i + 1] = s[i];
    }
    t[len - 1] = '#';

    for (int i = 0; i < len; i++) {
        int mirror = 2 * center - i;

        if (i < right) {
            p[i] = (right - i < p[mirror]) ? right - i : p[mirror];
        } else {
            p[i] = 0;
        }

        while (i + 1 + p[i] < len && i - 1 - p[i] >= 0 && t[i + 1 + p[i]] == t[i - 1 - p[i]]) {
            p[i]++;
        }

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }

    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 0; i < len; i++) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIndex = i;
        }
    }

    free(p);

    int start = (centerIndex - maxLen) / 2;
    int end = start + maxLen;
    char* result = (char*)malloc((end - start + 1) * sizeof(char));
    strncpy(result, s + start, end - start);
    result[end - start] = '\0';

    free(t);

    return result;
}

int main() {
    char str[] = {'a', 'b', 'c', 'a', 'b', 'c', 'b', 'b', '\0'};
    //char str[] = {'b', 'b', '\0'};
    //char str[] = "bb";
    char *s;

    s = longestPalindrome(str);

    printf("The palindrome string is %s\n", s);

    return 0;
}