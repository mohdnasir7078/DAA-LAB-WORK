/*Ques3.Given a directed graph, design an algorithm and implement
it using a program to find whether cycle exists in the graph or not */
#include <iostream>
#include <vector>
#include <stdbool.h>
using namespace std;
bool IsCycle(int src, vector<vector<int>> &adj, vector<bool> &stack, vector<bool> &visited)
{
    stack[src] = true;
    if (visited[src] == false)
    {
        visited[src] = true;
        for (auto j : adj[src])
        {
            if (visited[j] == false && IsCycle(j, adj, stack, visited))
                return true;
            if (stack[j] == true)
                return true;
        }
    }
    stack[src] = false;
    return false;
}
int main()
{
    int vertex = 0, edges;
    cin >> edges;
    vector<vector<int>> matrix;
    vector<int> temp;
    for (int i = 0; i < edges; i++)
    {
        for (int j = 0; j < edges; j++)
        {
            int t;
            cin >> t;
            temp.push_back(t);
            if (t == 1)
                vertex++;
        }
        matrix.push_back(temp);
        temp.clear();
    }
    vector<vector<int>> adj(vertex);
    for (int i = 0; i < edges; i++)
        for (int j = 0; j < edges; j++)
            if (matrix[i][j] == 1)
                adj[i].push_back(j);
    bool cycle = false;
    vector<bool> stack(vertex, false);
    vector<bool> visited(vertex, false);
    for (int i = 0; i < edges; i++)
    {
        if (visited[i] == false && IsCycle(i, adj, stack, visited))
        {
            cycle = true;
        }
    }
    if (cycle)
        cout << "Yes Cycle Exixts.";
    else
        cout << "No Cycle Exits";
    return 0;
}