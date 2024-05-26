#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

long long maximumHappinessSum(int* happiness, int happinessSize, int k) {
    long long sum = 0;
    int position = 0, decrement = 0;
    
    qsort(happiness, happinessSize, sizeof(int), compare);

    while(k) {
        sum = sum + ((happiness[position] - decrement > 0) ? happiness[position] - decrement : 0);
        position++;
        decrement++;
        k--;
    }
    return sum;
}

int main() {
    int happiness[] = {1, 2, 3};
    int size = sizeof(happiness) / sizeof(int);

    long long total = maximumHappinessSum(happiness, size, 2);
    printf("The total happiness is %lld", total);
    return 0;
}