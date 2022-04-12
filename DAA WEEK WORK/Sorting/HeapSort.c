/*Write a C programe to Sort and Array using HeapSort*/
#include <stdio.h>
#include <stdlib.h>
void Heapify(int *arr, int size, int i);
void HeapSort(int *arr, int size);
void PrintArray(int *arr, int size);
void swap(int *arr, int i, int largest);
int main()
{
    int size, i;
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    HeapSort(arr, size);
    PrintArray(arr, size);
}
void Heapify(int *arr, int size, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && arr[largest] < arr[l])
        largest = l;
    if (r < size && arr[largest] < arr[r])
        largest = r;
    if (largest != i)
    {
        /*int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;*/
        swap(arr, i, largest);
        Heapify(arr, size, largest);
    }
}
void swap(int *arr, int i, int largest)
{
    int temp;
    temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
}
void HeapSort(int *arr, int size)
{
    int i;
    for (i = (size / 2) - 1; i >= 0; i--)
        Heapify(arr, size, i);
    for (i = size - 1; i > 0; i--)
    {
        /*int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;*/
        swap(arr, 0, i);
        Heapify(arr, i, 0);
    }
}
void PrintArray(int *arr, int size)
{
    int i = 0;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
