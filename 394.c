#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* decodeString(char* s) {
    char* stack = (char*)malloc(10000 * sizeof(char));
    char* temp = (char*)malloc(10000 * sizeof(char));
    int array[30] = {0}, arrayIndex = -1;
    int top = -1, i = 0, count = 0, j = 0;
    
    while(s[i] != '\0') {
        if(s[i] >= '0' && s[i] <= '9') {
            j = i;
            count = 0;
            while(s[j] != '[') {
                count = (count * 10) + s[j] - '0';
                j++;
            }
            array[++arrayIndex] = count;
            i = j - 1; //  Take the i pointer to the '[' bracket
        } else if(s[i] == ']') {
            j = top;
            while(stack[j] != '[') 
                j--;
            for(int k = 0;k < array[arrayIndex];k++) {
                strcat(temp, stack + j + 1);
            }
            arrayIndex--;
            strcpy(stack + j, temp);
            for(int k = 0 ;temp[k] != '\0';k++) 
                temp[k] = '\0';
            top = strlen(stack) - 1;
        } else {
            stack[++top] = s[i];
        }
        i++;
    }
    
    free(temp);
    
    return stack;
}

int main() {
    char*  str = "3[a]2[bc]";

    printf("The string before decoding is '%s'\n", str);

    printf("The string after decoding is '%s'\n", decodeString(str));
    return 0;
}
