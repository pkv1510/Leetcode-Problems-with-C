#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool isAnagram(char* s, char* t) {
    if(strlen(t) > strlen(s))
        return false;
    int str[26] = {0};
    int i = 0;
    while(s[i] != '\0') {
        str[s[i] - 'a']++;
        i++;
    }
    i = 0;
    while(t[i] != '\0') {
        str[t[i] - 'a']--;
        i++;
    }
    for(int i = 0;i < 26;i++) {
        if(str[i] > 0)
            return false;
    }
    return true;
}

int main() {
    char *str1 = "anagram";
    char *str2 = "gnarama";

    if(isAnagram(str1, str2))
        printf("The target string '%s' is anagram of '%s'\n", str2, str1);
    else
        printf("The target string '%s' is not anagram\n", str2);
}