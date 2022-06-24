/*Ques3. Given an unsorted array of elements, design an algorithm and implement it using a program to
find whether majority element exists or not. Also find median of the array. A majority element is
an element that appears more than n/2 times, where n is the size of array.*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> vrr(n);
    for (int i = 0; i < n; i++)
        cin >> vrr[i];
    int median = vrr[n / 2];
    sort(vrr.begin(), vrr.end());
    int count = 1, temp = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (vrr[i] == vrr[i + 1])
            count++;
        else
        {
            if (count >= (n / 2))
            {
                cout << "Yes";
                temp = 1;
            }
            count = 1;
        }
    }
    if (!temp)
        cout << "NO";
    cout<<"\n"<<median;
    return 0;
}