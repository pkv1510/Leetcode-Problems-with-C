#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* gcdOfStrings(char* str1, char* str2) {
    int ptr = 0;

    while((str1[ptr] != '\0') && (str2[ptr] != '\0')) {
        if(str1[ptr] == str2[ptr])
            ptr++;
        else
            return "";
    }

    if((str1[ptr] == '\0') && (str2[ptr] == '\0'))
        return str2;

    if(strlen(str1) > strlen(str2)) {
        return gcdOfStrings(str1 + ptr, str2);
    } else {
        return gcdOfStrings(str1, str2 + ptr);
    }
}

int main() {
    char *arr1 = "ABABAB";
    char *arr2 = "ABAB";

    printf("The Greatest common divisor in the strings is '%s'\n", gcdOfStrings(arr1, arr2));

    return 0;
}
