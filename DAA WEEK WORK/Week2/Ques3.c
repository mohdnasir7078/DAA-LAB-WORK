/*Ques3(Week2).Given an array of nonnegative integers, design an
algorithm and a program to count the number of pairs
of integers such that their difference is equal to a
given key, K.*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int DiffrencePairs(int *arr, int size);
int main()
{
    int test;
    printf("Please input no of test case :");
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
        printf("%d\n", DiffrencePairs(arr, size));
    }

    return 0;
}
int DiffrencePairs(int *arr, int size)
{
    int diff, count = 0;
    printf("Please Enter a Difference :");
    scanf("%d", &diff);
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            if (abs(arr[i] - arr[j]) == diff)
                count++;
    return count;
}