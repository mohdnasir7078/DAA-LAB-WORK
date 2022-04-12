#include <stdio.h>
#include <stdlib.h>
void PrintArray(int *arr, int size);
void InsertionSort(int *arr, int size);
int main()
{
    int size, i;
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    InsertionSort(arr, size);
    PrintArray(arr, size);
}
void InsertionSort(int *arr, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        j=i-1;
        while (j>=0 && temp>arr[i])
        {
            arr[j]=arr[j+1];
            j--;
        }
        arr[j+1]=
        
    }
}
void PrintArray(int *arr, int size)
{
    int i = 0;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}