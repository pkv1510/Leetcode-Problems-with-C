#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

char vowels[] = {'a', 'e', 'i', 'o', 'u'};

bool isVowel(char c) {
    int size = (*(&vowels + 1) - vowels);
    for(int i = 0;i < size;i++) {
        if(c == vowels[i])
            return true;
    }
    return false;
}

int maxVowels(char* s, int k) {
    int left = 0, right = k, count = 0;
    for(int i = 0;i < k;i++) {
        if(isVowel(s[i]))
            count++;
    }
    int max = count;
    while(right < strlen(s)) {
        if(isVowel(s[left++]))
            count--;
        if(isVowel(s[right++]))
            count++;

        if(count > max)
            max = count;
    }

    return max;
}

int main() {
    char *str = "abciiidef";
    int k = 3;

    printf("The maximum number of vowels present in a substring of length %d is %d\n", k, maxVowels(str, k));

    return 0;
}
