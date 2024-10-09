#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* predictPartyVictory(char* senate) {
    int radCount = 0, direCount = 0, radBan = 0, direBan = 0;
    int head = 0, last, tail, i;
    for(i = 0;senate[i] != '\0';i++) {
        if(senate[i] == 'R') {
            radCount++;
        } else {
            direCount++;
        }
    }

    tail = i;
    last = i + 1;
    char c;
    while((direCount > 0) && (radCount > 0)) {
        c = senate[head];
        head = (head + 1) % last;
        if(c == 'R') {
            if(radBan > 0) {
                radBan--;
                radCount--;
            } else {
                direBan++;
                senate[tail] = 'R';
                tail = (tail + 1) % last;
            }
        } else {
            if(direBan > 0) {
                direBan--;
                direCount--;
            } else {
                radBan++;
                senate[tail] = 'D';
                tail = (tail + 1) % last;
            }
        }
    }

    return (direCount > 0) ? "Dire" : "Radiant";
}

int main()  {
    char senate[] = {'R', 'D', '\0'};

    printf("The Output of the Dota2Seate game is %s\n", predictPartyVictory(senate));

    return 0;
}
