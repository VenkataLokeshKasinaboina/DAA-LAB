#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n, edges;

    // Step 1: Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> n;

    // Step 2: Number of edges
    cout << "Enter the number of edges: ";
    cin >> edges;

    int graph[100][100] = {0};

    // Step 3: Enter edges
    cout << "Enter edges (source destination weight):\n";

    for (int i = 0; i < edges; i++)
    {
        int u, v, weight;

        cin >> u >> v >> weight;

        graph[u - 1][v - 1] = weight;
        graph[v - 1][u - 1] = weight;
    }

    int parent[100];
    int key[100];
    bool mstSet[100];

    // Step 4: Initialize
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
        parent[i] = -1;
    }

    // Step 5: Start from vertex 1
    key[0] = 0;

    // Step 6: Prim's Algorithm
    for (int count = 0; count < n - 1; count++)
    {
        int minKey = INT_MAX;
        int u = -1;

        // Find minimum key vertex
        for (int v = 0; v < n; v++)
        {
            if (!mstSet[v] && key[v] < minKey)
            {
                minKey = key[v];
                u = v;
            }
        }

        // Add vertex to MST
        mstSet[u] = true;

        // Update adjacent vertices
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != 0 &&
                !mstSet[v] &&
                graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Step 7: Display MST
    int totalWeight = 0;

    cout << "\nMinimum Spanning Tree:\n";
    cout << "Edge\tWeight\n";

    for (int i = 1; i < n; i++)
    {
        cout << parent[i] + 1
             << " - "
             << i + 1
             << "\t"
             << graph[i][parent[i]]
             << endl;

        totalWeight += graph[i][parent[i]];
    }

    cout << "\nTotal weight of MST = "
         << totalWeight << endl;

    return 0;
}
