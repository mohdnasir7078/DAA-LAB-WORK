/*Ques2(Week2).Given a sorted array of positive integers, design an
algorithm and implement it using a program to find three
indices i, j, k such that arr[i] + arr[j] = arr[k]*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void IndexFound(int *arr, int size);
int main()
{
    int test;
    printf("Please Input No of Test Caase :");
    scanf("%d", &test);
    while (test--)
    {
        int size;
        printf("Enter Array size :");
        scanf("%d", &size);
        printf("Input Array Elements.\n");
        int *arr = (int *)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++)
            scanf("%d", &arr[i]);
        IndexFound(arr, size);
    }

    return 0;
}
void IndexFound(int *arr, int size)
{
    int i, j, k;
    for (i = 0; i < size; i++)
        for (j = i + 1; j < size; j++)
            for (k = j + 1; k < size; k++)
                if ((arr[i] + arr[j]) == arr[k])
                {
                    printf("%d, %d, %d\n", i + 1, j + 1, k + 1);
                    break;
                }
    if (i == size)
        printf("No Sequence Found\n");
}