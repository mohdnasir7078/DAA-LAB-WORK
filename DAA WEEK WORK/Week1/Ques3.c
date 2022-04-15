/*Ques3. Given an already sorted array of positive integers, design
an algorithm and implement it using a program to find whether
a given key element is present in the sorted array or not. For
an array arr[n], search at the indexes arr[0], arr[2], arr[4],
.....,arr[2k] and so on. Once the interval (arr[2k] < key < arr
[ 2k+1] ) is found, perform a linear search operation from the
index 2k to find the element key. (Complexity < O(n), where n is
the number of elements need to be scanned for searching): */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
bool BinarySearch(int *arr, int size, int *comparisons);
int main()
{
    int test;
    printf("Please Enter No of Test :");
    scanf("%d", &test);
    while (test--)
    {
        int size, comparisons = 0;
        printf("Enter Array size :");
        scanf("%d", &size);
        printf("Input Array Elements.\n");
        int *arr = (int *)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++)
            scanf("%d", &arr[i]);
        if (BinarySearch(arr, size, &comparisons))
            printf("Present\n");
        else
            printf("Not Present\n");
        printf("%d", comparisons);
    }
    return 0;
}
bool BinarySearch(int *arr, int size, int *comparisons)
{
    int key, mid, j;
    printf("Please Enter a key :");
    scanf("%d", &key);
    for (int i = 0; j < size; i++)
    {
        j = pow(2, i);
        *(comparisons) = *(comparisons) + 1;
        if (arr[j] == key)
            return true;
    }
    return false;
}