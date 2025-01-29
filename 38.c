#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* countAndSay(int n) {
    if(n==1) return "1";
    char* str = countAndSay(n-1);
    char* ret = (char*)malloc(4463*sizeof(char));
    char ch = str[0];
    int freq = 1;
    int idx = 0;

    for(int i = 1;i < strlen(str);i++) {
        char dh = str[i];
        if(ch == dh) {
            freq++;
        } else {
            ret[idx++] = freq+'0';
            ret[idx++] = ch;
            freq = 1;
            ch = dh;
        }
    }
    ret[idx++] = freq+'0';
    ret[idx++] = ch;
    ret[idx] = '\0';
    return ret;
}

int main() {
    char* str = countAndSay(4);
    printf("String is %s\n", str);
}