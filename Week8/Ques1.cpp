/*Ques1. Assume that a project of road construction to connect some
cities is given to your friend. Map of these cities and roads which
will connect them (after construction) is provided to him in the form
of a graph. Certain amount of rupees is associated with construction
of each road. Your friend has to calculate the minimum budget required
for this project. The budget should be designed in such a way that the
cost of connecting the cities should be minimum and number of roads required
to connect all the cities should be minimum (if there are N cities then only
N-1 roads need to be constructed). He asks you for help. Now, you have to help
your friend by designing an algorithm which will find minimum cost required to
connect these cities. (use Prim's algorithm)*/
#include <bits/stdc++.h>
using namespace std;
#define V 7
int minimumnodevertex(vector<int> weight, vector<bool> process)
{
    int vertex;
    int minimum = INT_MAX;
    for (int i = 0; i < V; i++)
    {
        if (minimum > weight[i] && process[i] == false)
        {
            minimum = weight[i];
            vertex = i;
        }
    }
    return vertex;
}
void findMST(int graph[V][V])
{
    vector<int> parent(V, -1);
    vector<int> weight(V, INT_MAX);
    vector<bool> process(V, false);
    int MinimumWight = 0;
    weight[0] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        int minvertex = minimumnodevertex(weight, process);
        process[minvertex] = true;
        for (int j = 0; j < V; j++)
        {
            if (graph[minvertex][j] != 0 && process[j] != true && graph[minvertex][j] < weight[j])
            {
                weight[j] = graph[minvertex][j];
                parent[j] = minvertex;
            }
        }
    }
    for (int i = 1; i < V; ++i)
        MinimumWight += graph[parent[i]][i];
    cout << "Minimum Spanning Weight  :" << MinimumWight;
}
int main()
{
    int graph[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];
    findMST(graph);
    return 0;
}