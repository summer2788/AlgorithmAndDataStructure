#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// In-degree version
class Graph
{
public:
    Graph(int n) : n(n), inDegree(n, 0), adj(n) {}

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        inDegree[v]++;
    }

    vector<int> topologicalSort()
    {
        vector<int> result;
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            result.push_back(u);

            for (int v : adj[u])
            {
                inDegree[v]--;
                if (inDegree[v] == 0)
                    q.push(v);
            }
        }

        return result.size() == n ? result : vector<int>();
    }

private:
    int n;
    vector<int> inDegree;
    vector<vector<int>> adj;
};

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    vector<int> result = g.topologicalSort();
    if (result.empty())
        cout << "Graph has a cycle\n";
    else
    {
        for (int v : result)
            cout << v << " ";
        cout << "\n";
    }

    return 0;
}
