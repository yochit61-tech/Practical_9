#include <iostream>
using namespace std;

int main()
{
    int n, cost[20][20], visited[20];
    int i, j, edges = 0;
    int min, a, b, mincost = 0;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> cost[i][j];

            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;

    cout << "Edges in Minimum Spanning Tree:\n";

    while (edges < n - 1)
    {
        min = 999;

        for (i = 0; i < n; i++)
        {
            if (visited[i] == 1)
            {
                for (j = 0; j < n; j++)
                {
                    if (visited[j] == 0 && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (min == 999)
        {
            cout << "Graph is disconnected.\n";
            return 0;
        }

        cout << a << " - " << b
             << " : " << min << endl;

        mincost = mincost + min;
        visited[b] = 1;
        edges++;
    }

    cout << "Minimum cost = " << mincost << endl;

    return 0;
}
