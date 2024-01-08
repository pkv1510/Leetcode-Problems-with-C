#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Method - 2 : It takes 0ms to execute
char* convert(char* s, int numRows) {
    if(numRows <= 1 || strlen(s) <= 1) {
        return s;
    }
	int length = strlen(s);
	char *sHead = s;
	char *resultHead = (char*)malloc(length + 1);
	char *result = resultHead;
	for (int i = 0; i < numRows; i++)
	{
		s = sHead;
		s = s + i;
		while(s - sHead < length){
			*result = *s;
			result++;
			if(i != 0 && i != numRows - 1){
				if ((s + 2 *numRows) - 2 - 2 * i - sHead < length)
				{
					*result = s[((2 * numRows) - 2 - 2 * i)];
					result++;
				}
                else{
                    break;
                }
			}
			if (s - sHead + (2 * numRows) - 2 >= length)
			{
				break;
			}
				s = s + (2 * numRows) - 2;
		}
	}
    s = sHead;
    memcpy(s, resultHead, length);
    free(resultHead);
	return s;
}

//Method - 1 : It takes 3ms to execute
char* convert1(char* s, int numRows) {
    int totalSwap = numRows * 2 - 2;
    int leftSwap = totalSwap, rightSwap = 0;
    int totalLen = strlen(s);
    char *c = (char*)malloc(strlen(s) + 1);
    int j = 0, currLen = 0;

    if(totalLen == 1 || numRows == 1) {
        return s;
    }

    for(int i = 0;i < numRows;i++) {
        currLen = i;

        while(currLen < totalLen) {
            if(leftSwap == rightSwap && currLen < totalLen) {
                c[j++] = s[currLen];
                currLen = currLen + (totalSwap / 2);
            }
            else {
                if(leftSwap && currLen < totalLen) {
                    c[j++] = s[currLen];
                    currLen = currLen + leftSwap;
                }
                if(rightSwap && currLen < totalLen) {
                    c[j++] = s[currLen];
                    currLen = currLen + rightSwap;
                }
            }
        }
        leftSwap = leftSwap - 2;
        rightSwap = rightSwap + 2;
    }
    c[j] = '\0';
    strcpy(s, c);
    free(c);

    return s;
}

int main() {
    char str[] = "PAYPALISHIRING";
    //char str[] = "prabhavkumarvaish";
    //char str[] = "A";
    int numRows = 3;

    char* res = convert(str, numRows);
    printf("The zigzag string is %s\n", res);

    return 0;
}