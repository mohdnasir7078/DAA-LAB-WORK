/*Ques1(Week2). Given a sorted array of positive integers containing few
duplicate elements, design an algorithm and implement it using
a program to find whether the given key element is present in
the array or not. If present, then also find the number of copies
of given key. (Time Complexity = O(log n))*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int BinarySearch(int *arr, int low, int high, int *comparisons);
int main()
{
    int test;
    printf("Input No of Test :");
    scanf("%d", &test);
    while (test--)
    {
        int size, comparisons = 0, index = 0;
        printf("Enter Array size :");
        scanf("%d", &size);
        printf("Input Array Elements.\n");
        int *arr = (int *)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++)
            scanf("%d", &arr[i]);
        index = BinarySearch(arr, 0, size, &comparisons);
        int i = index - 1, j = index + 1, count = 1;
        if (!index)
            printf("Not Present ");
        else
        {
            while (arr[i] == arr[index] || arr[j] == arr[index])
            {
                if ((i < 0 && j >= size) || (arr[i] != arr[index] && arr[j] != arr[index]))
                    break;
                if (i >= 0 && arr[i] == arr[index])
                {
                    i--;
                    count++;
                }
                if (j < size && arr[j] == arr[index])
                {
                    j++;
                    count++;
                }
            }
            printf("%d -> %d\n", arr[index], count);
        }
    }

    return 0;
}
int BinarySearch(int *arr, int low, int high, int *comparisons)
{
    int key, mid;
    printf("Please Enter a key :");
    scanf("%d", &key);
    while (low < high)
    {
        mid = (low + high) / 2;
        *(comparisons) = *(comparisons) + 1;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}