#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void printArray(int *arr, int size) {
    for(int i = 0;i < size;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void updateTemp(int *temp, char *letters, int lettersSize){
    for(int i = 0;i < 26;i++)
        temp[i] = 0;

    for(int i = 0;i < lettersSize;i++)
        temp[letters[i] - 'a']++;
}

void revertScore(char *word, int k, int len, int *temp, int *score) {
    while(k >= 0) {
        temp[word[k--] - 'a']++;
    }
}

int maxScoreWords(char** words, int wordsSize, char* letters, int lettersSize, int* score, int scoreSize) {
    int *temp = (int *)calloc(26, sizeof(int));
    int maxScore = 0;

    for(int i = 0;i < lettersSize;i++)
        temp[letters[i] - 'a']++;

    for(int i = 0;i < wordsSize;i++) {
        int iterScore = 0;
        for(int j = i;j < wordsSize;j++) {
            char *word = words[j];
            int k = 0, wordScore = 0;
            printf("Word is %s\n", word);
            while(word[k] != '\0') {
                printf("letter is %c\n", word[k]);
                if((--temp[word[k] - 'a']) < 0) {
                    revertScore(word, k, strlen(word), temp, score);
                    printArray(temp, 26);
                    wordScore = 0;
                    break;
                } else {
                    wordScore += score[word[k] - 'a'];
                }
                k++;
            }
            iterScore += wordScore;
        }
        if(iterScore > maxScore)
            maxScore = iterScore;

        /* Revert the temp */
        updateTemp(temp, letters, lettersSize);
    }

    return maxScore;
}

int n;
char freq[26];
bool wordPossible(char freqw[26], int* wordScore, const char* w, const int* score){
    int wordScorePrev =* wordScore;
    for(int i = 0;w[i] != '\0';i++) {
        int idx = w[i]-'a';
        freqw[idx]--;
        *wordScore += score[idx];
        if (freqw[idx] < 0) {
            *wordScore = wordScorePrev;
            return 0;
        }
    }
    return 1;
}

int ans;
void dfs(int i, char* letters, int* wordScore, char** words, int* score)
{
    if (i == n)
        return;

    char lettersPrev[26];
    memcpy(lettersPrev, letters, 26);
    int wordScorePrev = *wordScore;
    
    if (wordPossible(letters, wordScore, words[i], score)){
        printf("words[%d] can %d \n", i, *wordScore);
        ans = (ans >= *wordScore) ? ans: *wordScore;
        dfs(i+1, letters, wordScore, words, score);
    } else {
        printf("words[%d] cannot %d \n", i, *wordScore);
    }
    dfs(i+1, lettersPrev, &wordScorePrev, words, score);
}

int maxScoreWords1(char** words, int wordsSize, char* letters, int lettersSize, int* score, int scoreSize) {
    n = wordsSize, ans=0;
    memset(freq, 0, sizeof(freq));
    for(int i=0; i<lettersSize; i++)
        freq[letters[i]-'a']++;
    
    int wordScore = 0;
    dfs(0, freq, &wordScore, words, score);
    return ans;
}

int main() {
    char **words = (char **)malloc(sizeof(char *));
    for(int i = 0;i < 6;i++)
        words[i] = (char *)malloc(sizeof(char *) * 4);

    words[0] = "ac";
    words[1] = "abd";
    words[2] = "db";
    words[3] = "ba";
    words[4] = "dddd";
    words[5] = "bca";
    char letters[] = {'a', 'a', 'a', 'b', 'b', 'b', 'c', 'c', 'd', 'd', 'd', 'd'};
    int score[] = {6,4,4,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int wordsSize = 6;
    int lettersSize = sizeof(letters);
    int scoreSize = sizeof(score) / sizeof(int);

    printf("The maximum score can be %d\n", maxScoreWords1(words, wordsSize, letters, lettersSize, score, scoreSize));
    return 0;
}