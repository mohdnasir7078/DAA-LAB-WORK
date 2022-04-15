#include <stdio.h>
#include <stdlib.h>
int Partition(int *arr, int low, int high);
int QuickSelect(int *arr, int low, int high, int K);
int main()
{
    int size, K, i;
    printf("Input the size of Array :");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    printf("Input the Array Elements.\n");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    printf("Enter the number 'K' to find 'Kth' Largest Elements :");
    scanf("%d", &K);
    printf("Kth Largest Elemenets is :%d\n", QuickSelect(arr, 0, size - 1, K));
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}
int QuickSelect(int *arr, int low, int high, int K)
{
    if (low == high)
        return arr[low];
    int PivotIndex = Partition(arr, low, high);
    int SizeofArray = PivotIndex - low + 1;
    if (SizeofArray > K)
        return QuickSelect(arr, low, PivotIndex - 1, K);
    else if (SizeofArray < K)
        return QuickSelect(arr, PivotIndex + 1, high, K - SizeofArray);
    else
        return arr[PivotIndex];
}
int Partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while (i <= j)
    {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}