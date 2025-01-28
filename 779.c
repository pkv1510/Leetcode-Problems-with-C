#include<stdio.h>

int kthGrammar(int n, int k) {
    if(n==1) return 0;
    else if(k%2 != 0) {
        return kthGrammar(n-1, k/2 +1);
    }
    else if(k%2 == 0) {
        int val = kthGrammar(n-1, k/2);
        if(val) return 0;
        else return 1;
    }
    return 0;
}

int main() {
    int n = 2;
    int k = 2;
    printf("Printing the Kth grammar %d\n",kthGrammar(n, k));
}