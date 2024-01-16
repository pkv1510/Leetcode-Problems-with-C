#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 2147483647
#define MIN (-2147483648)

int isDigit(char c) {
    if(c >= '0' && c <= '9')
        return 1;

    return 0;
}

int myAtoi(char *s) {
    int len = strlen(s);
    int sign = 1, result = 0;
    int i = 0;

    while(i < len && s[i] == ' ')
        i++;
    
    if(s[i] == '-') {
        sign = -1;
        i++;
    }
    else if(s[i] == '+') {
        sign = 1;
        i++;
    }

    while(i < len && isDigit(s[i])) {
        int digit = s[i] - '0';
        if(result > MAX / 10 || (result == MAX / 10 && digit > MAX % 10)) {
            return (sign == 1 ? MAX : MIN);
        }
        result = result * 10 + digit;
        i++;
    }

    return sign * result;
}

int main()
{
    char *str = "2147483646";
    //char *str = "    -42";
    printf("The integer representation of %s is %d\n", str, myAtoi(str));

    return 0;
}