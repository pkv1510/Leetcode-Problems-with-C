#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX_SIZE 10000

int stack[MAX_SIZE] = {};
int top = -1;
bool isPos = true;

void push(int s) {
    stack[++top] = s;
    if(s >= 0)
        isPos = true;
    else
        isPos = false;
}

bool checkNum(int s) {
    return (s >= 0) ? true : false;
}

void pop() {
    top--;
    if(top != -1)  {
        if(checkNum(stack[top]))
            isPos = true;
        else
            isPos = false;
    }
}

void printArray(int *arr, int size) {
    for(int i = 0;i < size;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int c = 0;
    int* res = (int*)malloc(asteroidsSize * sizeof(int));
    for(int i = 0;i < asteroidsSize;i++) {
        if((c > 0) && (res[c - 1] > 0) && (asteroids[i] < 0)) { //When Collision occurs
            while((c > 0) && (res[c - 1] >  0) && (abs(asteroids[i]) > res[c - 1])) {
                c--;
            }
            if(c && abs(asteroids[i]) == res[c - 1]) {
                c--;
                continue;
            }
            if(!c || res[c - 1] < 0) {
                res[c] = asteroids[i];
                c++;
            }
        } else { //No Collision
            res[c]  = asteroids[i];
            c++;
        }
    }
    *returnSize = c;
    return res;
}

int* asteroidCollision1(int* asteroids, int asteroidsSize, int* returnSize) {
    for(int i = 0;i < asteroidsSize;i++) {
        if((top == -1) || (isPos & checkNum(asteroids[i]))) {
            push(asteroids[i]);
        } else {
            if(isPos && (stack[top] + asteroids[i] > 0 )) {
                continue;
            }
            else if(!isPos && (stack[top] + asteroids[i] < 0)) {
                continue;
            } else {
                top--;
            }
        }
    }
    *returnSize = top + 1;
    int* res = (int*)malloc((top + 1) * sizeof(int));
    while(top != -1){
        res[top] = stack[top];
        top--;
    }
    return res;
}

int main() {
    //int asteroids[] = {8, -8};
    int asteroids[] = {1, -2, -2, -2};
    //int asteroids[] = {-2, -2, 1, -2};
    //int asteroids[] = {-2, -1, 1, -2};
    //int asteroids[] = {10, 2, -5};
    int size = *(&asteroids + 1) - asteroids;
    int retSize;

    printf("The original array is as :-\n");
    printArray(asteroids, size);

    int *ret = asteroidCollision(asteroids, size, &retSize);
    printf("The array after the collision is as :-\n");
    printArray(ret, retSize);

    return 0;
}
