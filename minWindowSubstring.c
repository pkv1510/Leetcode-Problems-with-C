#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* minWindow(char* s, char* t) {
    int sLen = strlen(s);
    int hash1[64] = {0};
    int hash2[64] = {0};
    int i = 0, tLen = 0;
    int mask = 0x3f;
    int left = 0;

    while(t[i] != '\0') {
        hash1[t[i] & mask]++;
        tLen++;
        i++;
    }

    int count = 0, minLeft = 0;
    int minLen = __INT_MAX__;

    for(int i = 0;i < sLen;i++) {
        if(!hash1[s[i] & mask])
            continue;

        hash2[s[i] & mask]++;
        if(hash2[s[i] & mask] <= hash1[s[i] & mask])
            count++;

        if(count == tLen) {
            int idxLeft;
            while((hash1[idxLeft = (s[left] & mask)] == 0) || (hash2[idxLeft] > hash1[idxLeft])) {
                if(hash2[idxLeft] != 0)
                    hash2[idxLeft]--;
                left++;
            }

            if((i - left + 1) < minLen) {
                minLen = i -left + 1;
                minLeft = left;
            }
        }
    }

    if(minLen == __INT_MAX__)
        return "";

    return s+minLeft;
}

int main()
{
    char *str = "ADOBECODEBANC";
    char *t = "ABC";
    char *ret = minWindow(str, t);

    printf("The window of minimum size with the %s string is %s\n", t, ret);

    return 0;
}