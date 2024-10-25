#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int compare(const void* a, const void*b) {
    return *(int*)a - *(int*)b;
}

bool closeStrings(char* word1, char* word2) {
    int hash1[26] = {};
    int hash2[26] = {};
    if(strlen(word1) != strlen(word2))
        return false;
    while(*word1 != '\0') {
        hash1[*word1++ - 'a']++;
    }
    while(*word2 != '\0') {
        hash2[*word2++ - 'a']++;
    }
    // This loop checks that whether the alphabets in the words are matching or not 
    for(int i = 0;i < 26;i++) {
        if(((bool)hash1[i] ^ (bool)hash2[i])){
            return false;
        }
    }
    // Now check that whetehr the total number of words are present 
    // in words is equal or not
    // To do this yo need to sort the hashmaps and then compare 
    // If they are not equal then return false
    qsort(hash1, 26, sizeof(int), compare);
    qsort(hash2, 26, sizeof(int), compare);
    for(int i = 0;i < 26;i++)  {
        if(hash1[i] != hash2[i])
            return false;
    }
    return true;
}

int main() {
    char *word1 = "a", *word2 = "aa";

    if(closeStrings(word1, word2)) {
        printf("You can attain word2 from word1\n");
    } else {
        printf("You can not attain word2 from word1\n");
    }

    return 0;
}
