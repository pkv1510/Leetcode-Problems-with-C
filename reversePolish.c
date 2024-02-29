#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int evalRPN(char** tokens, int tokensSize) {
    int stack[tokensSize];
    int top = -1, temp = 0;

    for(int i = 0;i < tokensSize;i++) {
        if(tokens[i] == "+") {
            temp = stack[top--];
            stack[top] = stack[top] + temp;
        } else if(tokens[i] == "-") {
            temp = stack[top--];
            stack[top] = stack[top] - temp;
        } else if(tokens[i] == "/") {
            temp = stack[top--];
            stack[top] = stack[top] / temp;
        } else if(tokens[i] == "*") {
            temp = stack[top--];
            stack[top] = stack[top] * temp;
        } else {
            stack[++top] = atoi(tokens[i]);
        }
    }
    return stack[top];
}

int main()
{
    char *str[] = {"2", "1", "+", "3", "*"};
    int size = sizeof(str);

    printf("The Sum after the polish expressions is %d \n", evalRPN(str, 5));

    return 0;
}