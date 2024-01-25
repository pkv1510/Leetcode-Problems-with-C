#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* intToRoman(int num) {
    char *roman = (char*)malloc(15);
    int i = 0;
    memset(roman, 0, 15);

    while(num != 0) {
        if(num >= 1000) {
            roman[i++] = 'M';
            num -= 1000;
        } else if(num >= 900) {
            roman[i++] = 'C';
            roman[i++] = 'M';
            num -= 900;
        } else if(num >= 500) {
            roman[i++] = 'D';
            num -= 500;
        } else if (num >= 400) {
            roman[i++] = 'C';
            roman[i++] = 'D';
            num -= 400;
        } else if(num >= 100) {
            roman[i++] = 'C';
            num -= 100;
        } else if(num >= 90) {
            roman[i++] = 'X';
            roman[i++] = 'C';
            num -= 90;
        } else if(num >= 50) {
            roman[i++] = 'L';
            num -= 50;
        } else if(num >= 40) {
            roman[i++] = 'X';
            roman[i++] = 'L';
            num -= 40;
        } else if(num >= 10) {
            roman[i++] = 'X';
            num -= 10;
        } else if(num >= 9) {
            roman[i++] = 'I';
            roman[i++] = 'X';
            num -= 9;
        } else if(num >= 5) {
            roman[i++] = 'V';
            num -= 5;
        } else if(num >= 4) {
            roman[i++] = 'I';
            roman[i++] = 'V';
            num -= 4;
        } else {
            if(num == 3) {
                roman[i++] = 'I';
                roman[i++] = 'I';
                roman[i++] = 'I';
            } else if(num == 2) {
                roman[i++] = 'I';
                roman[i++] = 'I';
            }
            else {
                roman[i++] = 'I';
            }
            num -= num;
        }
    }
    return roman;
}

char* intToRoman1(int num) {
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