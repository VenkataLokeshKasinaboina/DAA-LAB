#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    int cost[10][10];

    cout << "Enter cost matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    int path[10];

    for(int i = 0; i < n; i++)
    {
        path[i] = i;
    }

    int minCost = 999999;
    int bestPath[10];

    do
    {
        int totalCost = 0;
        bool valid = true;

        for(int i = 0; i < n - 1; i++)
        {
            if(cost[path[i]][path[i+1]] == 999)
            {
                valid = false;
                break;
            }

            totalCost += cost[path[i]][path[i+1]];
        }

        if(valid && cost[path[n-1]][path[0]] != 999)
        {
            totalCost += cost[path[n-1]][path[0]];

            if(totalCost < minCost)
            {
                minCost = totalCost;

                for(int i = 0; i < n; i++)
                    bestPath[i] = path[i];
            }
        }

    } while(next_permutation(path + 1, path + n));

    if(minCost == 999999)
    {
        cout << "No possible tour exists.";
    }
    else
    {
        cout << "\nMinimum travelling cost: " << minCost;

        cout << "\nBest path: ";

        for(int i = 0; i < n; i++)
            cout << bestPath[i] + 1 << " -> ";

        cout << bestPath[0] + 1;
    }

    return 0;
}
