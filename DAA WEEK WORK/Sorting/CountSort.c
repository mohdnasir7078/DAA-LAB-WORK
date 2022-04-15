#include <stdio.h>
#include <stdlib.h>
void PrintArray(int *arr, int size);
void SortArray(int *arr, int size, int max);
int MaxElement(int *arr, int size);
int main()
{
    int size, i, max;
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    max = MaxElement(arr, size);
    SortArray(arr, size, max);
}
int MaxElement(int *arr, int size)
{
    int max = INT_MIN, i = 0;
    for (i = 0; i < size; i++)
        if (max < arr[i])
            max = arr[i];
    return max;
}
void SortArray(int *arr, int size, int max)
{
    int *temp = (int *)malloc((max + 1) * sizeof(int));
    int i = 0;
    for (i = 0; i <= max; i++)
        temp[i] = 0;
    for (i = 0; i < size; i++)
        temp[arr[i]] = temp[arr[i]] + 1;
    for (i = 0; i <= max; i++)
    {
        int var = temp[i];
        while (var >= 1)
        {
            printf("%d ", i);
            var--;
        }
    }
}