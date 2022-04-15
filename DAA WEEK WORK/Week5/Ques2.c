/*Ques2(Week5). Given an unsorted array of integers, design an
algorithm and implement it using a program to find whether two
elements exist such that their sum is equal to the given key
element. (Time Complexity = O(n log n))*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void MergeSort(int *arr, int *temp, int low, int high);
void MergeElements(int *arr, int *temp, int low, int mid, int high);
bool SumCheck(int *arr, int low, int high);
int main()
{
    int test;
    printf("Test Cases :");
    scanf("%d", &test);
    while (test--)
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
        if (!(SumCheck(arr, 0, size - 1)))
            printf("No Such Pairs Exist.\n");
    }

    return 0;
}
bool SumCheck(int *arr, int low, int high)
{
    int sum, temp = 0;
    printf("input sum :");
    scanf("%d", &sum);
    while (low < high)
    {
        if ((arr[low] + arr[high]) == sum)
        {
            printf("%d %d\n", arr[low], arr[high]);
            low++;
            high--;
            temp = 1;
        }
        else if ((arr[low] + arr[high]) > sum)
            high--;
        else
            low++;
    }
    if (!temp)
        return false;
    else
        return true;
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