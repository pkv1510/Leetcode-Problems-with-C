#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include <string.h>

char** wordSubsets(char** words1, int words1Size, char** words2, int words2Size, int* returnSize) {
    int maxFreq[26] = {0};

    for (int j = 0; j < words2Size; j++) {
        int tempFreq[26] = {0};
        int idx = 0;
        while (words2[j][idx] != '\0') {
            tempFreq[words2[j][idx] - 'a']++;
            idx++;
        }
        for (int k = 0; k < 26; k++) {
            if (tempFreq[k] > maxFreq[k]) {
                maxFreq[k] = tempFreq[k];
            }
        }
    }

    char **ret = (char **)malloc(words1Size * sizeof(char *));
    *returnSize = 0;

    for (int i = 0; i < words1Size; i++) {
        int wordFreq[26] = {0};
        int idx = 0;
        while (words1[i][idx] != '\0') {
            wordFreq[words1[i][idx] - 'a']++;
            idx++;
        }

        bool conti = true;
        for (int k = 0; k < 26; k++) {
            if (wordFreq[k] < maxFreq[k]) {
                conti = false;
                break;
            }
        }

        if (conti) {
            ret[*returnSize] = words1[i];
            (*returnSize)++;
        }
    }

    return ret;
}


int main() {
    char *words1[] = {"amazon","apple","google","facebook", "leetcode"};
    int size1 = *(&words1 + 1) - words1;

    char *words2[] = {"lo", "eo"};
    int size2 = *(&words2 + 1) - words2;

    int returnSize = 0;

    char **res;
    res = wordSubsets(words1, size1, words2, size2, &returnSize);

    printf("The list is as : ");
    for(int i = 0;i < returnSize;i++) {
        printf("%s ", res[i]);
    }
    printf("\n");

    return 0;
}