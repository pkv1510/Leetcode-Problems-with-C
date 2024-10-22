#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * mergeAlternately(char * word1, char * word2){
    int size = strlen(word1) + strlen(word2);
    int j = 0, k = 0;
    char* merged = (char*)malloc((size+1) * sizeof(char));
    for(int i = 0;i < size;i++) {
        if((j < strlen(word1)) && ((i % 2 == 0) || (k >= strlen(word2)))) {
            merged[i] = word1[j++];
        } else {
            merged[i] = word2[k++];
        }
    }
    merged[size] = '\0';
    return merged;
}

int main() {
    char *arr1 = "abc";
    char *arr2 = "pqr";

    char *ret = mergeAlternately(arr1, arr2);

    printf("The string after concatenating is %s\n", ret);

    return 0;
}
