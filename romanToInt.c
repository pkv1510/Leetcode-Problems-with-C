#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int sToInt(char* s) {
    int num = 0;
    int i = 0;

    while(s[i] != '\0') {
        if(s[i] == 'M') {
            num += 1000;
            i++;
        } else if(s[i] == 'D') {
            num += 500;
            i++;
        } else if (s[i] == 'C') {
            i++;
            num += 100;
            if(s[i] == 'M') {
                i++;
                num += 800;
            } else if(s[i] == 'D') {
                i++;
                num += 300;
            }
        } else if(s[i] == 'L') {
            i++;
            num += 50;
        } else if (s[i] == 'X') {
            i++;
            num += 10;
            if(s[i] == 'C') {
                num += 80;
                i++;
            } else if(s[i] == 'L') {
                num += 30;
                i++;
            }
        } else if(s[i] == 'V') {
            i++;
            num += 5;
        } else if(s[i] == 'I') {
            i++;
            num += 1;
            if(s[i] == 'X') {
                i++;
                num += 8;
            } else if(s[i] == 'V') {
                i++;
                num += 3;
            }
        } else {
            return -1;
        }
    }
    return num;
}

int main()
{
    char *str = "MCMXCIV";

    printf("The integer value of %s is %d\n", str, sToInt(str));

    return 0;
}