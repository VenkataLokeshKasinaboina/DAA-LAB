#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge
struct Edge
{
    int u, v, weight;
};

// Find the parent of a vertex
int findParent(int parent[], int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent, parent[x]);
}

// Join two sets
void unionSets(int parent[], int rank[], int u, int v)
{
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);

    if (rootU != rootV)
    {
        if (rank[rootU] < rank[rootV])
            parent[rootU] = rootV;
        else if (rank[rootU] > rank[rootV])
            parent[rootV] = rootU;
        else
        {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int main()
{
    int V, E;

    // Input number of vertices and edges
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    // Input edges
    cout << "\nEnter edges (source destination weight):\n";

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

    // Sort edges according to weight
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b)
         {
             return a.weight < b.weight;
         });

    // Parent and rank arrays
    int *parent = new int[V];
    int *rank = new int[V];

    // Initially, every vertex is its own parent
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    int totalWeight = 0;
    int edgesSelected = 0;

    cout << "\nEdges selected in Minimum Spanning Tree:\n";

    // Process edges in increasing order of weight
    for (int i = 0; i < E && edgesSelected < V - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        // Check whether adding this edge creates a cycle
        int rootU = findParent(parent, u);
        int rootV = findParent(parent, v);

        if (rootU != rootV)
        {
            cout << u << " -- " << v
                 << " = " << weight << endl;

            totalWeight += weight;
            edgesSelected++;

            unionSets(parent, rank, u, v);
        }
    }

    // Display total cost
    cout << "\nMinimum Cost of Spanning Tree = "
         << totalWeight << endl;

    delete[] parent;
    delete[] rank;

    return 0;
}
