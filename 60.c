#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* getSubstr(char* str, int idx) {
    int size = strlen(str);
    int j = 0;
    for(int i = 0;i < size;i++) {
        if(i == idx)
            continue;
        str[j++] = str[i];
    }
    str[j] = '\0';
    return str;
}

char* Helper(char* str, char* ret, int k, int id) {
    int n = strlen(str);
    if(n==1) {
        ret[id++] = str[0];
        ret[id] = '\0';
        return ret;
    }
    int fact = 1;
    for(int i = 2;i < n;i++)
        fact *= i;

    int idx = k/fact;
    if(k % fact == 0) {
        idx--;
    }
    ret[id]= str[idx];
    char* left = getSubstr(str, idx);
    if(k%fact == 0) fact = fact;
    else fact = k%fact;

    return Helper(left,ret,fact, id+1);
}

char* getPermutation(int n, int k) {
    char* str = (char*)malloc((n+1) * sizeof(char));
    for(int i = 0;i < n;i++) {
        str[i] = i+'0'+1;
    }
    str[n] = '\0';
    char *ret=(char*)malloc((n+1)*sizeof(char));
    return Helper(str, ret,k, 0);
}

int main() {
    char* str = getPermutation(3,3);
    printf("%s\n", str);
}