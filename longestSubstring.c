#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Method - 1 (Using 2 for loops)
int lengthOfLongestSubstring(char* s) {
    int maxLen = 0;
    int first = 0, currLen = 0;

    for(int i = 0;s[i];i++) {
        for(int j = first;j < i;j++) {
            if(s[i] == s[j]) {
                first = j + 1;
                break;
            }
            else
                currLen++;
        }
        currLen = i - first + 1;
        if(currLen > maxLen)
            maxLen = currLen;
    }
    
    return maxLen;
}

//Method -2 (Using 1 for loop)
int lengthOfLongestSubstring1(char* s) {
    int first, maxLen = 0, currLen = 0;
    char temp;
    int pos[128] = { 0 };

    for (int i = 0;s[i]; i++) {
        currLen++;
        temp = s[i];
        first = i - pos[temp] + 1;
        pos[temp] = i + 1;
        currLen = currLen < first ? currLen : first;
        maxLen = maxLen > currLen ? maxLen : currLen;
    }

    return maxLen;
}

int main() {
    //char str[] = {'a', 'b', 'c', 'a', 'b', 'c', 'b', 'b', '\0'};
    char *str = "pwwkew";
    //char str[] = {'a', 'a', 'a', 'a', '\0'};
    int len;

    len = lengthOfLongestSubstring(str);
    printf("%d", len);

    return 0;
}