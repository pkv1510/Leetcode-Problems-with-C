#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* reverseWords(char* s) {
    int start = 0, len = strlen(s);
    int wordCount = 0, end = 0;

    int** words = (int**)malloc(len * sizeof(int*));
    for(int i = 0;i < len;i++) {
        words[i] = (int*)malloc(2 * sizeof(int));
    }

    int i = 0;
    while(i < len) {
        while((i < len) && s[i] == ' ')
            i++;

        if(i == len)
            break;

        start = i;

        while((i < len) && s[i] != ' ')
            i++;

        end = i - 1;
        words[wordCount][0] = start;
        words[wordCount][1] = end;
        wordCount++;
    }

    char* res = (char*)malloc((len + 1) * sizeof(char));
    int index = 0;
    for(int i = wordCount - 1;i >= 0;--i) {
        for(int j = words[i][0];j <= words[i][1];++j) {
            res[index++] = s[j];
        }
        if(i)
            res[index++] = ' ';
    }
    res[index] = '\0';

    for(int i = 0;i < len;i++) {
        free(words[i]);
    }
    free(words);

    return res;
}

int main() {
    char* str = "the sky is blue";

    printf("The string before reversing is '%s'\n", str);
    printf("The string after reversing is '%s'\n", reverseWords(str));

    return 0;
}
