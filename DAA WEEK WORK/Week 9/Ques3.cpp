#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, sum = 0, MinimumCost = 0;
    cin >> n;
    vector<int> vrr(n);
    for (int i = 0; i < n; i++)
        cin >> vrr[i];
    sort(vrr.begin(), vrr.end());
    for (int i = 1; i < vrr.size(); i++)
    {
        vrr[i] = vrr[i - 1] + vrr[i];
        MinimumCost+=vrr[i];
    }
    cout << MinimumCost;
    return 0;
}