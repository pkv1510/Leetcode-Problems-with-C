#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printStringArray(char **ret, int size) {
    for(int i = 0;i < size;i++) {
        printf("%s\n", ret[i]);
    }
}

static const int mapLen[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};

static const char *map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void fillLetters(char **ret, int rem, char *digits, char buf[5], int *idx, int *returnSize, int bufIdx) {
    if(!rem) {
        char *temp = (char *)calloc(bufIdx + 1, sizeof(char));
        memcpy(temp, buf, bufIdx);
        ret[*idx] = temp;
        *idx += 1;
        return;
    }
    int size = *digits - '0';

    for(int i = 0;i < mapLen[size];i++) {
        buf[bufIdx] = map[size][i];
        fillLetters(ret, rem - 1, &digits[1], buf, idx, returnSize, bufIdx + 1);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    int len = strlen(digits);
    if(!len) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = 1;
    for(int i = 0;i < len;i++)
        *returnSize *= mapLen[digits[i] - '0'];
    
    char **ret = (char**)calloc(*returnSize, sizeof(char *));

    char buf[5] = { 0 };
    int retIdx = 0;

    fillLetters(ret, len, digits, buf, &retIdx, returnSize, 0);

    return ret;
}

int main()
{
    char *str = "23";
    int size;
    char **ret = letterCombinations(str, &size);

    printf("The array of strings returned looks as :\n");
    printStringArray(ret, size);

    return 0;
}