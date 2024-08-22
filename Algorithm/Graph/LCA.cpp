#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define H 17

vector<vector<int>> adl;
vector<int> visited;
vector<vector<int>> parent;
vector<int> depth;

int lca(int a, int b)
{
    // set the depth equal
    if (depth[a] - depth[b] < 0)
    {
        swap(a, b);
    }

    int diff = depth[a] - depth[b];

    for (int i = 0; diff != 0; i++)
    {
        if (diff % 2 == 1)
        {
            a = parent[i][a];
        }
        diff >>= 1;
    }

    if (a == b)
    {
        return a;
    }

    for (int i = H - 1; i >= 0; i--)
    {
        if (parent[i][a] != parent[i][b])
        {
            a = parent[i][a];
            b = parent[i][b];
        }
    }

    return parent[0][a];
}

int main()
{
    int n = 9;
    adl = vector<vector<int>>(n);
    visited = vector<int>(n, 0);
    parent = vector<vector<int>>(H, vector<int>(n, 0));
    depth = vector<int>(n, 0);

    adl[0].push_back(1);
    adl[1].push_back(0);
    adl[0].push_back(2);
    adl[2].push_back(0);
    adl[1].push_back(3);
    adl[3].push_back(1);
    adl[1].push_back(4);
    adl[4].push_back(1);
    adl[2].push_back(5);
    adl[5].push_back(2);
    adl[4].push_back(6);
    adl[6].push_back(4);
    adl[4].push_back(7);
    adl[7].push_back(4);
    adl[5].push_back(8);
    adl[8].push_back(5);

    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        for (int i = 0; i < adl[here].size(); i++)
        {
            int there = adl[here][i];
            if (!visited[there])
            {
                q.push(there);
                visited[there] = 1;
                parent[0][there] = here;
                depth[there] = depth[here] + 1;
            }
        }
    }

    for (int i = 1; i < H; i++)
    {
        for (int j = 0; j < n; j++)
        {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }

    cout << lca(3, 5) << endl;
    cout << lca(6, 8) << endl;
    cout << lca(7, 8) << endl;
    cout << lca(3, 7) << endl;

    return 0;
}
