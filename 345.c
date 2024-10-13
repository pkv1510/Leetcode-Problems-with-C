#include<stdio.h>
#include<string.h>
#include<stdbool.h>

char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

void swapChar(char* s, int start, int end) {
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
}

bool isVowel(char c) {
    int size = (*(&vowels + 1) - vowels);
    for(int i = 0;i < size;i++) {
        if(c == vowels[i])
            return true;
    }
    return false;
}

char* reverseVowels(char* s) {
    int start = 0, end = strlen(s) - 1;
    while(start < end) {
        bool first = isVowel(s[start]);
        bool second = isVowel(s[end]);
        if(first && second) {
            swapChar(s, start, end);
            start++;
            end--;
        } else if(first) {
            end--;
        } else if(second) {
            start++;
        } else {
            start++;
            end--;
        }
    }
    return s;
}

int main() {
    char str[] = {'h','e','l','l','o','\0'};

    printf("The string before swapping the vowels is %s\n", str);
    printf("The string after swapping the vowels is %s\n", reverseVowels(str));

    return 0;
}
