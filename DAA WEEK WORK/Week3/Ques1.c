/*Ques1(Week3).Given an unsorted array of integers, design an algorithm and
a program to sort the array using insertion sort. Your program
should be able to find number of comparisons and shifts (shifts
total number of times the array elements are shifted from their
place) required for sorting the array.*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void InsertionSort(int *arr, int size, int *shifts, int *comparisions);
void PrintArray(int *arr, int size);
int main()
{
    int test;
    printf("Please Input No of Test Case :");
    scanf("%d", &test);
    while (test--)
    {
        int size, shifts = 0, comparisions = 0;
        printf("Enter Array size :");
        scanf("%d", &size);
        printf("Input Array Elements.\n");
        int *arr = (int *)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++)
            scanf("%d", &arr[i]);
        InsertionSort(arr, size, &shifts, &comparisions);
        PrintArray(arr, size);
        printf("\nComparisions = %d\nShifts = %d\n", comparisions, shifts);
    }

    return 0;
}
void InsertionSort(int *arr, int size, int *shifts, int *comparisions)
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            *(comparisions) = *(comparisions) + 1;
            arr[j + 1] = arr[j];
            j--;
        }
        *(shifts) = *(shifts) + 1;
        arr[j + 1] = key;
    }
    *(shifts) = *(shifts) + *(comparisions);
}
void PrintArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}