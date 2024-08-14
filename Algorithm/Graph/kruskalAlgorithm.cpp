#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> parent;
vector<pair<int, pair<int, int>>> edges;

int find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}

void Union(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u != v)
        parent[u] = v;
}

int kruskalAlgorithm(int n)
{
    int cost = 0;
    sort(edges.begin(), edges.end());
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;
        if (find(u) != find(v))
        {
            Union(u, v);
            cost += w;
        }
    }
    return cost;
}

int main()
{
    // make edge list
    edges.push_back({1, {0, 1}});
    edges.push_back({2, {1, 2}});
    edges.push_back({3, {2, 3}});
    edges.push_back({4, {3, 0}});
    edges.push_back({5, {0, 2}});
    edges.push_back({6, {1, 3}});
    // initialize parent
    for (int i = 0; i < 4; i++)
        parent.push_back(i);
    cout << kruskalAlgorithm(4) << endl;
    return 0;
}
