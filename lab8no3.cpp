#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random1to100();
void printAr(int numAr[], int numArSize);
int checkNum(int numAr[], int numArSize);
int searchNum(int numAr[], int numArSize, int target);

int main()
{
    int N, i;
    int A[100];

    scanf("%d", &N);
    if (N > 100)
        N = 100;

    srand(time(NULL));

    for (i = 0; i < N; i++)
        A[i] = checkNum(A, i);

    printf("\n********\n");
    printAr(A, N);

    return 0;
}

void printAr(int numAr[], int numArSize)
{
    for (int i = 0; i < numArSize; i++)
        printf("%d ", numAr[i]);
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

int random1to100()
{
    return (rand() % 100) + 1;
}