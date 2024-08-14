#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

struct Edge
{
    int to, weight;
};

vector<vector<Edge>> adj;
vector<int> dist;

void dijkstra(int start)
{
    dist.assign(adj.size(), INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u])
            continue;
        for (auto [v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        cout << "Distance from 0 to " << i << " is " << dist[i] << endl;
    }
    return 0;
}
