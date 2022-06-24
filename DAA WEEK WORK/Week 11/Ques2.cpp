/*Ques2. Given a set of available types of coins. Let suppose you have infinite supply of each type of coin.
For a given value N, you have to Design an algorithm and implement it using a program to find
number of ways in which these coins can be added to make sum value equals to N.*/
#include <bits/stdc++.h>
using namespace std;
int count(int S[], int m, int n)
{
	if (n == 0)
		return 1;
	if (n < 0)
		return 0;
	if (m <= 0 && n >= 1)
		return 0;
	return count(S, m - 1, n) +
		count(S, m, n - S[m - 1]);
}
int main()
{
	int n,m;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>m;
	cout << " " << count(arr, n, m);
	return 0;
}