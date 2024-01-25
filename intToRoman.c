#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* intToRoman1(int num) {
    char *roman = (char*)malloc(15);
    int i = 0, j = 14;
    memset(roman, 0, 15);

    while(num != 0) {
        if(num >= 900) {
            if(num >= 1000) {
                roman[i++] = 'M';
                num = num - 1000;
            }
            else {
                roman[j--] = 'M';
                num = 1000 - num;
            }
        } else if(num >= 400) {
            if(num >= 500) {
                roman[i++] = 'D';
                num = num - 500;
            }
            else {
                roman[j--] = 'D';
                num = 500 - num;
            }
        } else if(num >= 90) {
            if(num >= 100) {
                roman[i++] = 'C';
                num = num - 100;
            }
            else {
                roman[j--] = 'C';
                num =  100 - num;
            }
        } else if(num >= 40) {
            if(num >= 50) {
                roman[i++] = 'L';
                num = num - 50;
            }
            else {
                roman[j--] = 'L';
                num = 50 - num;
            }
        } else if(num >= 9) {
            if(num >= 10) {
                roman[i++] = 'X';
                num = num - 10;
            }
            else {
                roman[j--] = 'X';
                num = 10 - num;
            }
        } else if(num >= 4) {
            if(num >= 5) {
                roman[i++] = 'V';
                num = num - 5;
            }
            else {
                roman[j--] = 'V';
                num = 5 - num;
            }
        }
        else {
            if(num == 3) {
                roman[i++] = 'I';
                roman[i++] = 'I';
                roman[i++] = 'I';
            }
            else if(num == 2) {
                roman[i++] = 'I';
                roman[i++] = 'I';
            }
            else {
                roman[i++] = 'I';
            }
            num = 0;
        }
    }
    return roman;
}

char* intToRoman(int num) {
    int symbolVal[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 3, 2, 1};
    char* symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "III", "II", "I"};

    char *roman = (char*)malloc(15);
    int i = 0;

    while(num > 0) {
        while(num >= symbolVal[i]) {
            num = num - symbolVal[i];
            strcat(roman, symbol[i]);
        }
        i++;
    }
    
    return roman;
}

int main()
{
    int num = 98;
    
    printf("The Roman conversion of %d is %s\n", num, intToRoman(num));
    
    return 0;
}