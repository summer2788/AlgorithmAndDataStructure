#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[100]; // adjacency list pair: {weight, vertex}
vector<bool> visited(100, false);

int primAlgorithm(int start)
{
    int cost = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty())
    {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        cost += w;
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;
            if (!visited[v])
                pq.push({weight, v});
        }
    }
    return cost;
}

int main()
{
    adj[0].push_back({1, 1});
    adj[1].push_back({0, 1});
    adj[1].push_back({2, 2});
    adj[2].push_back({1, 2});
    adj[2].push_back({3, 3});
    adj[3].push_back({2, 3});
    adj[3].push_back({0, 4});
    adj[0].push_back({3, 4});
    adj[0].push_back({2, 5});
    adj[2].push_back({0, 5});
    adj[1].push_back({3, 6});
    adj[3].push_back({1, 6});
    cout << primAlgorithm(0) << endl;
    return 0;
}
