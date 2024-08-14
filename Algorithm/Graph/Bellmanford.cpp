#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
    int from, to, cost;
};

const int INF = 1e9;

vector<int> bellmanford(int n, vector<Edge> edges, int start)
{
    vector<int> dist(n, INF);
    dist[start] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (Edge edge : edges)
        {
            if (dist[edge.from] != INF && dist[edge.to] > dist[edge.from] + edge.cost)
            {
                dist[edge.to] = dist[edge.from] + edge.cost;
            }
        }
    }

    // Check for negative cycle
    for (Edge edge : edges)
    {
        if (dist[edge.from] != INF && dist[edge.to] > dist[edge.from] + edge.cost)
        {
            return vector<int>();
        }
    }

    return dist;
}

int main()
{
    int n = 5;
    vector<Edge> edges = {
        {0, 1, 1},
        {0, 2, 4},
        {1, 2, 2},
        {1, 3, 6},
        {2, 3, 3},
        {2, 4, 2},
        {4, 3, 1}};

    vector<int> dist = bellmanford(n, edges, 0);
    if (dist.empty())
    {
        cout << "Negative cycle detected" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Distance from 0 to " << i << " is " << dist[i] << endl;
        }
    }
    return 0;
}
