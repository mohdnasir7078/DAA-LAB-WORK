/*Given an unsorted array of integers, design an algorithm and
implement a program to sort this array using selection sort.
Your program should also find number of comparisons and number of
swaps required*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void SelectionSort(int *arr, int size, int *swap, int *comparisions);
void PrintArray(int *arr, int size);
int main()
{
    int size, swap = 0, comparisions = 0;
    ;
    printf("Enter Array size :");
    scanf("%d", &size);
    printf("Input Array Elements.\n");
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    SelectionSort(arr, size, &swap, &comparisions);
    PrintArray(arr, size);
    printf("\nComparisions = %d\nSwaps = %d", comparisions, swap);
    return 0;
}
void SelectionSort(int *arr, int size, int *swap, int *comparisions)
{
    int min, pos, i, j;
    for (i = 0; i < size; i++)
    {
        min = arr[i];
        pos = i;
        for (j = i + 1; j < size; j++)
        {
            *(comparisions) = *(comparisions) + 1;
            if (min > arr[j])
            {
                min = arr[j];
                pos = j;
            }
        }
        if (pos != i)
        {
            *(swap) = *(swap) + 1;
            arr[pos] = arr[i];
            arr[i] = min;
        }
    }
    printf("%d %d\n", comparisions, swap);
}
void PrintArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}