/*Given an unsorted array of positive integers, design an
algorithm and implement it using a program to find whether
there are any duplicate elements in the array or not.
(use sorting) (Time Complexity = O(n log n))*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
bool Dublicates(int *arr, int size);
int MaximumElement(int *arr, int size);
int main()
{
    int size;
    printf("Enter Array size :");
    scanf("%d", &size);
    printf("Input Array Elements.\n");
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    if (Dublicates(arr, size))
        printf("YES");
    else
        printf("NO");
    return 0;
}
bool Dublicates(int *arr, int size)
{
    int *temp = (int *)malloc((MaximumElement(arr, size) + 1) * sizeof(int));
    int i = 0;
    for (i = 0; i <= (MaximumElement(arr, size)); i++)
        temp[i] = 0;
    for (i = 0; i < size; i++)
        temp[arr[i]] = temp[arr[i]] + 1;
    for (i = 0; i <= (MaximumElement(arr, size)); i++)
        if (temp[i] >= 2)
            return true;
    return false;
}
int MaximumElement(int *arr, int size)
{
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
        if (max < arr[i])
            max = arr[i];
    return max;
}