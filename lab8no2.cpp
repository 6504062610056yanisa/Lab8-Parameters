#include <stdio.h>

int checkscore(char std[]);
int checkq1(char ans[][10]);

char keys[10] = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};

int main()
{
    int i,j;
    int correct[10] = {0};
    char ans[8][10] = {
        {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'},
        {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'},
        {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'},
        {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'},
        {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'D', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}
    };

    for (i = 0; i < 8; i++) {
        printf("std %d => %d\n", i + 1, checkscore(ans[i]));
    }

    printf("Question1 correct => %d \n", checkq1(ans));

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 10; j++) {
            if (ans[i][j] == keys[j]) {
                correct[j]++;
            }
        }
    }
    int min = correct[0];
    int hard = 0;

    for (j = 1; j < 10; j++) {
        if (correct[j] < min) {
            min = correct[j];
            hard = j;
        }
    }

    printf("Hardest question => question %d \n", hard + 1);

    return 0;
}

int checkscore(char std[])
{
    int score = 0;
    for (int i = 0; i < 10; i++) {
        if (std[i] == keys[i]) {
            score++;
        }
    }
    return score;
}

int checkq1(char ans[][10])
{
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (ans[i][0] == keys[0]) {
            count++;
        }
    }
    return count;
}

