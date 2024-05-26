#include<stdio.h>
#include<stdlib.h>

int checkAttendance(int n, int latesLeft, int absentsLeft) {
    if(n == 0)
        return 1;

    int numWays = 0;

    numWays += checkAttendance(n - 1, latesLeft, absentsLeft);

    if(latesLeft > 0)
        numWays += checkAttendance(n - 1, latesLeft - 1, absentsLeft);

    if(absentsLeft > 0)
        numWays += checkAttendance(n - 1, latesLeft, absentsLeft - 1);

    return numWays;
}

int checkRecord(int n) {
    return checkAttendance(n, 2, 1);
}

void updateDP(int **arr1, int **arr2) {
    for(int i = 0; i < 2;i++) {
        for(int j = 0;j < 3;j++) {
            arr1[i][j] = arr2[i][j];
        }
    }
}

int checkRecord1(int n) {
    int **prevDP = (int **)calloc(2, sizeof(int*));
    for(int i = 0;i < 2;i++) {
        prevDP[i] = (int *)calloc(3, sizeof(int));
    }
    prevDP[0][0] = 1;
    prevDP[0][1] = 1;
    prevDP[0][2] = 1;
    prevDP[1][0] = 1;
    prevDP[1][1] = 1;
    prevDP[1][2] = 1;
        
    for(int i = 1; i <= n; i++){
        int **newDP = (int **)calloc(2, sizeof(int*));
        for(int i = 0;i < 2;i++) {
            newDP[i] = (int *)calloc(3, sizeof(int));
        }

        for(int a = 0; a < 2; a++){
            for(int l = 0; l < 3; l++){
                newDP[a][l] += prevDP[a][2];
                if(a > 0)
                    newDP[a][l] += prevDP[a - 1][2];
                if(l > 0)
                    newDP[a][l] += prevDP[a][l - 1];
            }
        }
        updateDP(prevDP, newDP);
    }
    return prevDP[1][2];
}

int main() {
    int n;
    printf("Enter the number of days for which the possible number of attendances are requied\n");
    scanf("%d", &n);

    printf("The total number of ways a candidate is not removed is %d \n", checkRecord1(n));
    return 0;
}