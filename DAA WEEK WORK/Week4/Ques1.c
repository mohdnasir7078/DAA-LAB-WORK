/*Given an unsorted array of integers, design an algorithm and 
implement it using a program to sort an array of elements by 
dividing the array into two subarrays and combining these subarrays
after sorting each one of them. Your program should also find 
number of comparisons and inversions during sorting the array*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void MergeSort(int *arr, int *temp, int low, int high);
void MergeElements(int *arr, int *temp, int low, int mid, int high);
void PrintArray(int *arr, int size);
int comparisions = 0;
int main()
{
    int size;
    printf("Enter Array size :");
    scanf("%d", &size);
    printf("Input Array Elements.\n");
    int *arr = (int *)malloc(size * sizeof(int));
    int *temp = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    MergeSort(arr, temp, 0, size - 1);
    PrintArray(arr, size);
    printf("\nComparisions = %d", comparisions);
    return 0;
}
void MergeSort(int *arr, int *temp, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(arr, temp, low, mid);
        MergeSort(arr, temp, mid + 1, high);
        MergeElements(arr, temp, low, mid, high);
    }
}
void MergeElements(int *arr, int *temp, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        comparisions++;
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}
void PrintArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}