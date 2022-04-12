/* Given an unsorted array of alphabets containing duplicate elements. 
Design an algorithm and implement it using a program to find which 
alphabet has maximum number of occurrences and print it. 
(Time Complexity = O(n)) (Hint: Use counting sort)*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size, i, key, max = INT_MIN, pos = 0;
    char ch;
    printf("Please Input  Array size :");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    int *temp = (int *)malloc(26 * sizeof(int));
    for (i = 0; i < 26; i++)
        temp[i] = 0;
    for (i = 0; i < size; i++)
    {
        scanf(" %c", &ch);
        key = ch - 'a';
        arr[i] = key;
        if (max < arr[i])
            max = arr[i];
    }
    for (i = 0; i < size; i++)
        temp[arr[i]] = temp[arr[i]] + 1;
    int max1 = INT_MIN;
    for (i = 0; i <= max; i++)
    {
        if (max1 < temp[i])
        {
            max1 = temp[i];
            pos = i;
        }
    }
    if (max1 >= 2)
    {
        ch = 'a' + pos;
        printf("%c -> %d", ch, max1);
    }
    else
        printf("No Dublicates Present.");
    return 0;
}