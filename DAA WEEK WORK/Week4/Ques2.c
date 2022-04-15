/*Ques2(Week4). Given an unsorted array of integers, design an algorithm
and implement it using a program to sort an array of elements by
partitioning the array into two subarrays based on a pivot element
such that one of the sub array holds values smaller than the pivot
element while another sub array holds values greater than the pivot
element. Pivot element should be selected randomly from the array.
Your program should also find number of comparisons and swaps required
for sorting the array.*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void QuickSort(int *arr, int low, int high);
int ArrayPartition(int *arr, int low, int high);
void swap(int *arr, int start, int end);
void PrintArray(int *arr, int size);
int comparisions = 0, swaps = 0;
int main()
{
    int test;
    printf("Please input no of test case :");
    scanf("%d", &test);
    while (test--)
    {
        int size;
        comparisions = 0, swaps = 0;
        printf("Enter Array size :");
        scanf("%d", &size);
        printf("Input Array Elements.\n");
        int *arr = (int *)malloc(size * sizeof(int));
        int *temp = (int *)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++)
            scanf("%d", &arr[i]);
        QuickSort(arr, 0, size - 1);
        PrintArray(arr, size);
        printf("\nComparision = %d\nSwaps = %d\n", comparisions, swaps);
    }

    return 0;
}
int ArrayPartition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1, j = high;
    while (i <= j)
    {
        while (arr[i] <= pivot)
        {
            i++;
            comparisions++;
        }
        while (arr[j] > pivot)
        {
            j--;
            comparisions++;
        }
        /*swaps++;*/
        if (i < j)
        {
            swaps++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    swaps++;
    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}
void swap(int *arr, int start, int end)
{
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
}
void QuickSort(int *arr, int low, int high)
{
    int PartitionIndex;
    if (low < high)
    {
        int randomly = (rand() % (high - low + 1)) + low;
        swap(arr, low, randomly);
        PartitionIndex = ArrayPartition(arr, low, high);
        QuickSort(arr, low, PartitionIndex - 1);
        QuickSort(arr, PartitionIndex + 1, high);
    }
}
void PrintArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}