#include <stdio.h>
#include <stdlib.h>
void PrintArray(int *arr, int size);
void merge(int *arr, int *temp, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
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
        k++;
        j++;
    }
    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}
void MergeSort(int *arr, int *temp, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(arr, temp, low, mid);
        MergeSort(arr, temp, mid + 1, high);
        merge(arr, temp, low, mid, high);
    }
}
void PrintArray(int *arr, int size)
{
    int i = 0;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
int main()
{
    int size, i, max;
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    int *temp = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        temp[i] = 0;
    }
    MergeSort(arr, temp, 0, size - 1);
    PrintArray(temp, size);
}