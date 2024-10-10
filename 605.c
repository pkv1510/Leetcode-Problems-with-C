#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int count = 0;

    if(n > flowerbedSize)
        return false;
    if(n) {
        if(flowerbedSize == 1) {
            if(!flowerbed[0])
                return true;
            else
                return false;
        }
    } else {
        return true;
    }

    if((flowerbedSize == 2) && ((flowerbed[0] == 0) && (flowerbed[1] == 0))) {
        if(n > 1)
            return false;
        else
            return true;
    }
    if((flowerbed[0] == flowerbed[1]) && (!flowerbed[0])) {
        flowerbed[0] = 1;
        count++;
    }
    if((flowerbed[flowerbedSize - 2] == flowerbed[flowerbedSize - 1]) && (!flowerbed[flowerbedSize - 1])) {
        flowerbed[flowerbedSize - 1] = 1;
        count++;
    }
    for(int i = 1;i < flowerbedSize - 1;i++) {
        if(!flowerbed[i]) {
            if(flowerbed[i - 1] == flowerbed[i + 1]) {
                if(!flowerbed[i - 1]) {
                    count++;
                    i++;
                }
            }
        }
    }
    printf("%d", count);
    return (n <= count);
}

int main() {
    int arr[] = {0, 0, 1, 0, 1};
    int size = (*(&arr + 1) - arr);
    int n = 1;

    if(canPlaceFlowers(arr, size, n)) {
        printf("The %d number of flowers can be planted\n", n);
    } else {
        printf("The %d number of flowers can not be planted\n", n);
    }

    return 0;
}