#include<stdio.h>
#include<string.h>

void reverseString(char* s, int size) {
    int temp = size / 2;
    for (int i = 0;i < temp;i++) {
        s[i] ^= s[size - 1 - i];
        s[size - i - 1] ^= s[i];
        s[i] ^= s[size - i - 1];
    }
}

int main() {
    char str[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    int size = strlen(str);

    printf("The original string is '%s'\n", str);
    reverseString(str, size);
    printf("The string after the reverse is '%s'\n", str);
    return 0;
}