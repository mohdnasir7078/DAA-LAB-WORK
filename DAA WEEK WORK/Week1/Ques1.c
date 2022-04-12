/*Given an array of nonnegative integers, design a linear 
algorithm and implement it using a program to find whether 
given key element is present in the array or not. Also, find 
total number of comparisons for each input case. (Time Complexity 
= O(n), where n is the size of input)*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
bool LinearSearch(int *arr, int size, int *comparisons);
int main()
{
    int size, comparisons=0;
    printf("Enter Array size :");
    scanf("%d", &size);
    printf("Input Array Elements.\n");
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    if (LinearSearch(arr, size, &comparisons))
        printf("Present ");
    else
        printf("Not Present ");
    printf("%d", comparisons);
    return 0;
}
bool LinearSearch(int *arr, int size, int *comparisons)
{
    int key;
    printf("Please Enter a key :");
    scanf("%d", &key);
    for (int i = 0; i < size; i++)
    {
        *(comparisons)=*(comparisons)+1;
        if (arr[i] == key)
            return true;
    }
    return false;
}