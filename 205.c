#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool isIsomorphic(char* s, char* t) {
    int *str = (int*)malloc(150*sizeof(int));
    for(int i = 0;i < 150;i++)
        str[i] = 250;
    int i = 0;
    while(s[i] != '\0') {
        if(str[s[i]] != 250){
            if(str[s[i]] != s[i] - t[i])
                return false;
        }
        str[s[i]] = s[i] - t[i];
        i++;
    }
    for(int i = 0;i < 150;i++)
        str[i] = 250;
    i = 0;
    while(t[i] != '\0') {
        if(str[t[i]] != 250){
            if(str[t[i]] != s[i] - t[i])
                return false;
        }
        str[t[i]] = s[i] - t[i];
        i++;
    }
    return true;
}

int main() {
    char *str1 = "title";
    char *str2 = "paper";

    if(isIsomorphic(str1, str2))
        printf("The target string '%s' and '%s' are isomorphic\n", str2, str1);
    else
        printf("The target string '%s' and '%s' are not isomorphic\n", str2, str1);
}