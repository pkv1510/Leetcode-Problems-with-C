#include<stdio.h>
#include<stdlib.h>

int largestAltitude(int* gain, int gainSize) {
    int altitude = 0, maxAltitude = 0;
    for(int i = 0;i < gainSize;i++) {
        altitude += gain[i];

        if(altitude > maxAltitude)
            maxAltitude = altitude;
    }
    return maxAltitude;
}

int main() {
    //int gain[] = {-5,1,5,0,-7};
    int gain[] = {-4,-3,-2,-1,4,3,2};
    int size = *(&gain + 1) - gain;

    printf("The highest altitude in thee array is %d\n", largestAltitude(gain, size));

    return 0;
}