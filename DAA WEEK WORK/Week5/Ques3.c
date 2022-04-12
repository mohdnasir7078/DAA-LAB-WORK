/*You have been given two sorted integer arrays of size m and n.
Design an algorithm and implement it using a program to find list
of elements which are common to both. (Time Complexity = O(m+n))*/
#include <stdio.h>
#include <stdlib.h>
void SameElements(int *arr1, int *arr2, int size1, int size2)
{
    int i = 0, j = 0;
    while (i <= size1 && j <= size2)
    {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr1[i] > arr2[j])
            j++;
        else
        {
            printf("%d ", arr1[i]);
            i++;
            j++;
        }
    }
}
int main()
{
    int size1, size2, i;
    printf("Enter array1 size :");
    scanf("%d", &size1);
    printf("Enter array2 size :");
    scanf("%d", &size2);
    int *arr1 = (int *)malloc(size1 * sizeof(int));
    int *arr2 = (int *)malloc(size2 * sizeof(int));
    printf("Input array1 Elemenst.\n");
    for (i = 0; i < size1; i++)
        scanf("%d", &arr1[i]);
    printf("Input array2 Elemenst.\n");
    for (i = 0; i < size2; i++)
        scanf("%d", &arr2[i]);
    SameElements(arr1, arr2, size1, size2);
}