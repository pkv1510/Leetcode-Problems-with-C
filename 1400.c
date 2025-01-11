#include<stdio.h>
#include<stdbool.h>

bool canConstruct(char* s, int k) {
    int arr[26] = {0};
    int i = 0, size = 0;
    while(s[i] != '\0') {
        arr[s[i++] - 'a']++;
        size++;
    }
    if(size < k) return false;
    for(int i = 0;i < 26;i++) {
        if(arr[i]%2 == 1) k--;
        printf("%d ", arr[i]);
    }

    if(k < 0) return false;
    else return true;
}

int main() {
    char *str = "annabelle";
    int k = 2;

    if(canConstruct(str, k))
        printf("\nThe String %s can Construct\n", str);
    else
        printf("\nThe String %s can not Construct\n", str);

    return  0;
}
