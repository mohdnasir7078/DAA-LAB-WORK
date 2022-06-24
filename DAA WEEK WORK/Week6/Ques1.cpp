/*Ques1. Given a (directed/undirected) graph, design an algorithm
and implement it using a program to find if a path exists between
two given vertices or not. (Hint: use DFS)*/
#include <iostream>
#include <vector>
#include <stdbool.h>
using namespace std;
void DFS(int source, vector<vector<int>> matrix, vector<bool> &visited);
int main()
{
    int ch;
    cout << "1. For Adjacency Matrix as a Input." << endl;
    cout << "2. For Edges and Vertex as a Input." << endl;
    cin >> ch;
    if (ch == 1)
    {
        int source, destination, size, t;
        cout << "Input size :";
        cin >> size;
        vector<bool> visited(size, false);
        vector<vector<int>> matrix;
        vector<int> temp;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cin >> t;
                temp.push_back(t);
            }
            matrix.push_back(temp);
            temp.clear();
        }
        cout << "Input Source and Destination :";
        cin >> source >> destination;
        DFS(source - 1, matrix, visited);
        if (visited[destination - 1] == true)
            cout << "\nYes Path Exists.";
        else
            cout << "\nNo Such Path Exists.";
    }
    else
    {
        int source, destination;
        int edges, vertex;
        cout << "Input no of Vertex and Edges :";
        cin >> vertex >> edges;
        vector<bool> visited(vertex);
        vector<vector<int>> matrix;
        vector<int> temp;
        for (int i = 0; i < vertex; i++)
        {
            for (int j = 0; j < vertex; j++)
            {
                temp.push_back(0);
            }
            matrix.push_back(temp);
            temp.clear();
        }
        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cin >> u >> v;
            matrix[u - 1][v - 1] = 1;
        }
        cout << "Input Source and Destination :";
        cin >> source >> destination;
        DFS(source - 1, matrix, visited);
        if (visited[destination - 1] == true)
            cout << "\nYes Path Exists.";
        else
            cout << "\nNo Such Path Exists.";
    }
    return 0;
}
void DFS(int source, vector<vector<int>> matrix, vector<bool> &visited)
{
    printf("%d ", source);
    visited[source] = true;
    for (int neigh = 0; neigh < matrix.size(); neigh++)
    {
        if (matrix[source][neigh] == 1 && visited[neigh] == false)
            DFS(neigh, matrix, visited);
    }
}