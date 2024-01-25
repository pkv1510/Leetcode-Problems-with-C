#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool isUnique(char *s, int *len) {
    bool alpha[26] = {false};
    while(*s != '\0') {
        int idx = *s++ - 'a';
        if(alpha[idx])
            return false;
        alpha[idx] = true;
        (*len)++;
    }
    return true;
}

void tracing(int start, char** arr, char* currStr, int arrLen, int* maxLength) {
    int strLen = 0;
    if(isUnique(currStr, &strLen))
        *maxLength = (strLen > *maxLength) ? strLen : *maxLength;
    else
        return;

    for(int i = start;i < arrLen;i++) {
        char str[52] = {'\0'};
        strcat(str, currStr);
        strcat(str, arr[i]);
        tracing(i + 1, arr, str, arrLen, maxLength);
    }
}

int maxLength(char** arr, int arrSize) {
    int maxLen = 0;
    tracing(0, arr, "", arrSize, &maxLen);

    return maxLen;
}

int main()
{
    char *arr[] = {"un", "iq", "ue"};
    int size = 3;

    printf("The max length of the concatenated string is %d\n", maxLength(arr, size));
    return 0;
}
