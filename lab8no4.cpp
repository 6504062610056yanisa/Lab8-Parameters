#include <stdio.h>
#include <stdlib.h>

int random1to100();
void printAr(int numAr[], int numArSize);
int checkNum(int numAr[], int numArSize);
int searchNum(int numAr[], int numArSize, int target);

void bubbleSort(int a[], int n);
int best3sum_of4(int score[4], int best3[3]);

int main()
{
    int score[4];
    int best3[3];

    for (int i = 0; i < 4; i++)
    {
        score[i] = checkNum(score, i);
    }

    printf("All 4 scores: ");
    printAr(score, 4);

    int sum = best3sum_of4(score, best3);

    printf("Best 3 scores: ");
    printAr(best3, 3);

    return 0;
}

int random1to100()
{
    return (rand() % 100) + 1;
}

void printAr(int numAr[], int numArSize)
{
    for (int i = 0; i < numArSize; i++)
    {
        printf("%d ", numAr[i]);
    }
    printf("\n");
}

int checkNum(int numAr[], int numArSize)
{
    int rnum = random1to100();
    while (searchNum(numAr, numArSize, rnum))
    {
        rnum = random1to100();
    }
    return rnum;
}

int searchNum(int numAr[], int numArSize, int target)
{
    for (int i = 0; i < numArSize; i++)
    {
        if (numAr[i] == target)
            return 1;
    }
    return 0;
}

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

int best3sum_of4(int score[4], int best3[3])
{
    int tmp[4];
    for (int i = 0; i < 4; i++)
        tmp[i] = score[i];

    bubbleSort(tmp, 4);

    best3[0] = tmp[1];
    best3[1] = tmp[2];
    best3[2] = tmp[3];

    return best3[0] + best3[1] + best3[2];
}
