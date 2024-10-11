#include<stdio.h>
#include<stdlib.h>

void fillCount1(char* chars, int* j, int count) {
    int temp = count;
    while(count > 1) {
        if(count >= 1000) {
            chars[(*j)++] = (count / 1000) + '0';
            count = count % 1000;
        } else if(count >= 100) {
            chars[(*j)++] = (count / 100) + '0';
            count = count % 100;
        } else if(count >= 10) {
            chars[(*j)++] = (count / 10) + '0';
             count = count % 10;
        } else if(count > 1) {
            chars[(*j)++] = count + '0';
            break;
        }
    }

    if((temp > 1) && (count > 0))
        chars[(*j)++] = count + '0'; 
}

void fillCount(char* chars, int* j, int count) {
    int temp = count;
    int countArray[4];
    if(count >= 1000) {
        countArray[0] = count / 1000;
        count = count % 1000;
        countArray[1] = count / 100;
        count = count % 100;
        countArray[2] = count / 10;
        count = count % 10;
        countArray[3] = count;
    } else if(count >= 100) {
        countArray[0] = count / 100;
        count = count % 100;
        countArray[1] = count / 10;
        count = count % 10;
        countArray[2] = count;
        countArray[3] = -1;
    } else if(count >= 10) {
        countArray[0] = count / 10;
        count = count % 10;
        countArray[1] = count;
        countArray[2] = -1;
        countArray[3] = -1;
    } else {
        countArray[0] = count;
        countArray[2] = -1;
        countArray[1] = -1;
        countArray[3] = -1;
    }

    for(int i = 0;i < 4;i++) {
        if((temp > 1) && (countArray[i] >= 0)) {
            chars[(*j)++] = countArray[i] + '0';
        }
    }
}

int compress(char* chars, int charsSize) {
    if(charsSize == 1)
        return 1;
    if(!charsSize)
        return 0;

    int j = 0, count = 1; 
    for(int i = 0;i < charsSize - 1;i++) {
        if(chars[i] == chars[i + 1]) {
            count++;
        } else {
            chars[j++] = chars[i];
            fillCount(chars, &j, count);
            count = 1;
        }
    }
    chars[j++] = chars[charsSize - 1];
    fillCount(chars, &j, count);
    for(int i = j; i < charsSize;i++) {
        chars[j] = '\0';
    }
    return j;
}

int main() {
    char chars[] = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    //char chars[] = {'a', 'b', 'c'};
    int size = *(&chars + 1) - chars;

    printf("The compressed string is '%d' length\n", compress(chars, size));
    printf("The string after compression is '%s'\n", chars);
    return 0;
}
