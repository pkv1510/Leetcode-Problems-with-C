#include<stdio.h>

int prefixCount(char** words, int wordsSize, char* pref) {
    int count = 0;
    for(int i = 0;i < wordsSize;i++) {
        char *word = words[i];
        int id = 0;
        while((word[id] == pref[id]) && (pref[id] != '\0')) {
            id++;
        }
        if(pref[id] == '\0') count++;
    }
    return count;
}

int main() {
    char *words[] = {"pay","attention","practice","attend"};
    int size = *(&words + 1) - words;

    char *str = "at";

    printf("The number of words having the prefix as '%s' are %d\n", str, prefixCount(words, size, str));

    return 0;
}