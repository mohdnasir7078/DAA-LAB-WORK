/*Given an already sorted array of positive integers,
design an algorithm and implement it using a program
to find whether given key element is present in the
array or not. Also, find total number of comparisons
for each input case. (Time Complexity = O(nlogn),
where n is the size of input).*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
bool BinarySearch(int *arr, int low, int high, int *comparisons);
int main()
{
    int size, comparisons = 0;
    printf("Enter Array size :");
    scanf("%d", &size);
    printf("Input Array Elements.\n");
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    if (BinarySearch(arr, 0, size, &comparisons))
        printf("Present ");
    else
        printf("Not Present ");
    printf("%d", comparisons);
    return 0;
}
bool BinarySearch(int *arr, int low, int high, int *comparisons)
{
    int key, mid;
    printf("Please Enter a key :");
    scanf("%d", &key);
    while (low < high)
    {
        mid = (low + high) / 2;
        *(comparisons) = *(comparisons) + 1;
        if (arr[mid] == key)
            return true;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}