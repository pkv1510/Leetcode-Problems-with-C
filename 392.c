#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

bool isSubsequence(char* s, char* t) {
    int tlen = strlen(t);
    int slen = strlen(s);
    int  i = 0;
    for(int j = 0;j < tlen;j++) {
        if(i < slen) {
            if(s[i] == t[j]) {
                i++;
            }
        }
        else {
            return true;
        }
    }
    return (i == slen);
}

int main() {
    char *str1 = "abc";
    char *str2 = "ahbgdc";
    
    if(isSubsequence(str1, str2))
        printf("The string %s is the substring of %s\n", str1, str2);
    else
        printf("The string %s is the substring of %s\n", str1, str2);
 
    return 0;
}