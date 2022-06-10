/*Ques1. Given a list of activities with their starting time and finishing time. Your goal is to select
maximum number of activities that can be performed by a single person such that selected
activities must be non-conflicting. Any activity is said to be non-conflicting if starting time of an
activity is greater than or equal to the finishing time of the other activity. Assume that a person
can only work on a single activity at a time.*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    int size;
    cin >> size;
    vector<int> result;
    multimap<int, pair<int, int>> activity;
    for (int i = 0; i < size; i++)
    {
        int s, e;
        cin >> s >> e;
        activity.insert({e, make_pair(s, i + 1)});
    }
    int count = 0, next = -1;
    for (auto it = activity.begin(); it != activity.end(); it++)
    {
        if (it->second.first > next)
        {
            count++;
            next = it->first;
            result.push_back(it->second.second);
        }
    }
    cout << "No. of non-conflicting activities: " << count << endl;
    cout << "List of selected activities: ";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << ", ";
    return 0;
}