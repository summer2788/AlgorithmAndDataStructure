#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;

// floydWarshall

vector<vector<int>> floydWarshall(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] != 0)
                dist[i][j] = adj[i][j];
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}

int main()
{
    int n = 4;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][3] = 1;
    adj[3][0] = 1;
    vector<vector<int>> dist = floydWarshall(adj);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
