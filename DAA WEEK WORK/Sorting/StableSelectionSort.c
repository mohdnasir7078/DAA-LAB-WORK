#include <stdio.h>
#include <stdlib.h>
void StableSelectionSort(int *arr, int size);
void PrintArray(int *arr, int size);
int main()
{
    int size, i, max;
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    StableSelectionSort(arr, size);
    PrintArray(arr, size);
}
void StableSelectionSort(int *arr, int size)
{
    int min, i, pos, j;
    for (i = 0; i < size; i++)
    {
        min = arr[i];
        pos = i;
        for (j = i + 1; j < size; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                pos = j;
            }
        }
        if (pos != i)
        {
            while (pos> i)
            {
                arr[pos] = arr[pos - 1];
                pos--;
            }
            arr[i] = min;
        }
    }
}
void PrintArray(int *arr, int size)
{
    int i = 0;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}