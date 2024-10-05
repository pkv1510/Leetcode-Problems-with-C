#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100000

char stack[MAX_SIZE] = {'\0'};
int top = -1;

void push(char s) {
    stack[++top] = s;
}

void pop() {
    stack[top--] = '\0';
}

char* removeStars(char* s) {
    while(*s != '\0') {
        if(*s != '*')
            push(*s);
        else
            pop();

        *s++;
    }
    char* res = (char*)malloc((top + 2) * sizeof(char));
    res[top + 1] = '\0';
    while(top != -1){
        res[top] = stack[top];
        top--;
    }
    return res;
}

int main() {
    char* s = "leet**cod*e";

    printf("The string after removing stars(*) is %s\n", removeStars(s));

    return 0;
}
