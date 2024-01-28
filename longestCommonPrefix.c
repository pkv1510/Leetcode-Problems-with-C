#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int min = __INT_MAX__;
    for(int i = 0;i < strsSize;i++) {
        int len = strlen(strs[i]);
        if(min > len)
            min = len;
    }
    char *arr = (char *)calloc(200, 1);

    bool isDiff = false;

    for(int i = 0;i < min;i++) {
        for(int j = 0;j < strsSize - 1;j++) {
            if(strs[j][i] != strs[j + 1][i]) {
                isDiff = true;
                break;
            }
        }
        if(!isDiff)
            arr[i] = strs[0][i];
        else
            break;
    }

    return arr;
}

int main()
{
    char *str[] = {
                    "flower",
                    "flow",
                    "flight"
                };

    printf("The longest common subsequece is %s\n", longestCommonPrefix(str, 3));

    return 0;
}