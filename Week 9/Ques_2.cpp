/*Ques2.Given a knapsack of maximum capacity w . N items are provided , each having its own value and weight . You have to Design an algorithm and implement it using a program to find the list of the selected items such that the final selected content has weight w and has maximum value . You can take fractions of items , i.e . the items can be broken into smaller pieces so that you have to carry only a fraction x of item i , where 0<=x<=1*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    float weight, volume, capacity, PerUnit;
    map<float, pair<float, int>, greater<float>> mymap;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> weight >> volume;
        PerUnit = volume / weight;
        mymap.insert({PerUnit, make_pair(weight, i + 1)});
    }
    cin >> capacity;
    float MaxProfit = 0, we = 0;
    vector<pair<int, float>> item_weight;
    for (auto it = mymap.begin(); it != mymap.end(); it++)
    {
        MaxProfit += it->first * it->second.first;
        we += it->second.first;
        if (we < capacity)
            item_weight.push_back(make_pair(it->second.second, it->second.first));
        if (we > capacity)
        {
            float temp = 0;
            MaxProfit -= it->first * it->second.first;
            we -= it->second.first;
            temp = capacity - we;
            MaxProfit += it->first * temp;
            we += temp;
            item_weight.push_back(make_pair(it->second.second, temp));
        }
        if (we == capacity)
            break;
    }
    cout << "Maximum Value:" << MaxProfit << endl;
    cout << "item-weight" << endl;
    for (int i = 0; i < item_weight.size(); i++)
        cout << item_weight[i].first << " - " << item_weight[i].second << endl;
    return 0;
}