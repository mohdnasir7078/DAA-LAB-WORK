/*After end term examination, Akshay wants to party with his friends. All his friends are living as
paying guest and it has been decided to first gather at Akshay’s house and then move towards
party location. The problem is that no one knows the exact address of his house in the city.
Akshay as a computer science wizard knows how to apply his theory subjects in his real life and
came up with an amazing idea to help his friends. He draws a graph by looking in to location of
his house and his friends’ location (as a node in the graph) on a map. He wishes to find out
shortest distance and path covering that distance from each of his friend’s location to his house
and then whatsapp them this path so that they can reach his house in minimum time. Akshay has
developed the program that implements Dijkstra’s algorithm but not sure about correctness of
results. Can you also implement the same algorithm and verify the correctness of Akshay’s
results? (Hint: Print shortest path and distance from friends’ location to Akshay’s house)
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int minDisIndex(int *dis, bool *vis, int v)
{
    int i;
    int minDis = INT_MAX;
    int minIndex = -1;
    for (i = 0; i < v; i++)
    {
        if (vis[i] == false && dis[i] <= minDis)
        {
            minDis = dis[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(vector<vector<int>> mat, int v, int s)
{
    int dis[v];
    bool vis[v];
    int parent[v];
    int i, j;
    for (i = 0; i < v; i++)
    {
        dis[i] = INT_MAX;
        vis[i] = false;
        parent[i] = -1;
    }
    dis[s] = 0;
    parent[s] = s;
    for (i = 0; i < v; i++)
    {
        int m = minDisIndex(dis, vis, v);
        vis[m] = true;
        for (j = 0; j < v; j++)
        {
            if (dis[m] != INT_MAX && !vis[j] && mat[m][j])
            {
                if (dis[j] > dis[m] + mat[m][j])
                {
                    dis[j] = dis[m] + mat[m][j];
                    parent[j] = m;
                }
            }
        }
    }
    for (i = 0; i < v; i++)
    {
        if (i == s)
        {
            cout << i + 1 << " : " << dis[i] << endl;
            continue;
        }
        cout << i + 1;
        j = i;
        while (parent[j] != s)
        {
            cout << " " << parent[j] + 1;
            j = parent[j];
        }
        cout << " " << s + 1 << " : " << dis[i] << endl;
    }
}
int main()
{
    int i, j;
    int v;
    cin >> v;
    vector<vector<int>> mat(v, vector<int>(v));
    for (i = 0; i < v; i++)
        for (j = 0; j < v; j++)
            cin >> mat[i][j];
    int s;
    cin >> s;
    dijkstra(mat, v, s - 1);
    return 0;
}