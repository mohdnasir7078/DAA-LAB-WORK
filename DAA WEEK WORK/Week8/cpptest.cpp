#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int M, T;
    cin >> M >> T;
    while (M--)
    {
        int count = 1;
        vector<int> S(T);
        vector<int> N(T);
        vector<pair<int, int>> res;
        for (int i = 0; i < T; i++)
            cin >> S[i];
        for (int i = 0; i < T; i++)
            cin >> N[i];
        for (int i = 0; i < T; i++)
            res.push_back(make_pair(S[i], N[i]));
        sort(res.begin(), res.end());
        for (int i = 0; i < T - 1; i++)
            if (res[i].second > res[i + 1].second)
                count++;
        cout << count << "\n";
    }
    return 0;
}