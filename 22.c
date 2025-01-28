#include<stdio.h>
#include<stdlib.h>

void Helper(char** v, char* ret, int n, int open, int close, int idx, int *retSize) {
    if(close==n) {
        ret[idx] = '\0';
        v[*retSize] = (char*)malloc((2*n+1)*sizeof(char));
        for(int i = 0;i <= 2*n;i++) {
            v[*retSize][i] = ret[i];
        }
        (*retSize)++;
        return;
    }
    if(open < n) {
        ret[idx] = '(';
        Helper(v, ret, n, open+1, close, idx+1, retSize);
    }
    if(close < open) {
        ret[idx] = ')';
        Helper(v, ret, n, open, close+1, idx+1, retSize);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int size = 1 << (2*n);
    char **ret = (char**)malloc(size*sizeof(char*));
    char *temp = (char*)malloc((2*n+1)*sizeof(char));
    Helper(ret, temp,n, 0,0,0, returnSize);
    return ret;
}

int main() {
    int n = 1;
    int retSize = 0;
    char** str = generateParenthesis(n, &retSize);

    for(int i = 0;i < retSize;i++) {
        printf("%s\n", str[i]);
    }
}