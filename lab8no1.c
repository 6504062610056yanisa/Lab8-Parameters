
#include <stdio.h>

int findmax(int num[], int n);
void printar(int myar[]);
void addone(int number[], int add[]);
void addthree(int number[], int pos[][2], int posSize);

int main()
{
    int number[5] = {20, 50, 100, 199, 9};
    int add[5] = {1, 2, 3, 4, 5};

    int max = findmax(number, 5);

    printar(number);
    addone(number, add);

    int pos[3][2] =
        {
            {0, 5},
            {2, 10},
            {4, 3}};

    addthree(number, pos, 3);

    printf("max = %d\n", max);
    return 0;
}

void printar(int myar[])
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d %d\n", i, myar[i]);
    }
}

int findmax(int num[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (num[j] > num[j + 1])
            {
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
    return num[n - 1];
}

void addone(int number[], int add[])
{
    for (int i = 0; i < 5; i++)
    {
        number[i] += add[i];
        printf("%d ", number[i]);
    }
    printf("\n");
}

void addthree(int number[], int pos[][2], int posSize)
{
    for (int i = 0; i < posSize; i++)
    {
        int index = pos[i][0];
        int value = pos[i][1];
        number[index] += value;

        printf("index %d += %d -> %d\n", index, value, number[index]);
    }
}