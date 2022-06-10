/*Ques3.Assume that same road construction project is given to another person. The amount he will earn
from this project is directly proportional to the budget of the project. This person is greedy, so he
decided to maximize the budget by constructing those roads who have highest construction cost.
Design an algorithm and implement it using a program to find the maximum budget required for
the project.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
vector<pair<int, pair<int, int>>> graph;
vector<pair<int, pair<int, int>>> result;
int parent[10000];
using namespace std;
void make(int i)
{
    parent[i] = i;
}
int find(int V)
{
    if (V == parent[V])
        return V;
    return find(parent[V]);
}
void Union(int a, int b, int i)
{

    a = find(a);
    b = find(b);

    if (a != b)
    {
        parent[b] = a;
        result.push_back(graph[i]);
    }
}
void Kruskal(int V)
{
    sort(graph.rbegin(), graph.rend());

    int E = graph.size();
    int s, d, w;

    for (int i = 0; i < E; i++)
    {
        s = graph[i].second.first;
        d = graph[i].second.second;
        Union(s, d, i);
    }
}
int main()
{
    int V, E = 0;
    cin >> V;
    vector<vector<int>> matrix;
    vector<int> temp;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            int t;
            cin >> t;
            temp.push_back(t);
            if (t != 0)
                E++;
        }
        matrix.push_back(temp);
        temp.clear();
    }
    for (int i = 0; i < V; i++)
        make(i);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (matrix[i][j] != 0)
                graph.push_back(make_pair(matrix[i][j], make_pair(i, j)));
    int sum = 0;
    Kruskal(V);
    for (int i = 0; i < result.size(); i++)
    {
        int w = result[i].first;
        sum = sum + w;
    }
    cout << "Maximum Spanning weight :" << sum;
    return 0;
}