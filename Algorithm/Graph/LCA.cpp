#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int max_level;
vector<vector<int>> parent;
vector<int> depth;
vector<int> adj[100001];
vector<int> visited(100001, 0);

struct Graph
{
    int V;
    vector<vector<int>> adj;
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

int lca(int u, int v)
{
    if (depth[u] > depth[v])
        swap(u, v);
    for (int i = max_level; i >= 0; i--)
    {
        if (depth[v] - depth[u] >= (1 << i))
        {
            v = parent[v][i];
        }
    }
    if (u == v)
        return u;
    for (int i = max_level; i >= 0; i--)
    {
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main()
{
    // make temp graph
    Graph g(9);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(4, 6);
    g.addEdge(4, 7);
    g.addEdge(5, 8);

    // make parent, depth
    max_level = 20;
    parent.resize(9, vector<int>(max_level + 1));
    depth.resize(9, 0);

    queue<int> q;
    q.push(0);
    parent[0][0] = 0;

    for (int j = 1; j <= max_level; j++)
    {
        for (int i = 0; i < 9; i++)
        {
            if (parent[i][j - 1] == 0)
                parent[i][j] = 0;
            else
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int next : g.adj[cur])
        {
            if (!visited[next])
            {
                visited[next] = 1;
                depth[next] = depth[cur] + 1;
                parent[next][0] = cur;
                q.push(next);
            }
        }
    }

    cout << lca(6, 8) << '\n';
    cout << lca(3, 8) << '\n';
    cout << lca(4, 7) << '\n';
    cout << lca(3, 5) << '\n';
    cout << lca(1, 2) << '\n';
    return 0;
}
