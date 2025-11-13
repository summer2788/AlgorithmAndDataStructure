// BFS always construct shortest path .
// to find the simple path s to v, we can print v's parent recursively
// BFS construct Bread-first-tree which include simple path

#include <bits/stdc++.h>
using namespace std;

void BFS(const vector<vector<int>> &adj, int s) {
  int n = adj.size();
  vector<int> color(n, 0); // 0: WHITE, 1: GRAY, 2: BLACK
  vector<int> dist(n, INT_MAX);
  vector<int> parent(n, -1);

  queue<int> q;

  color[s] = 1; // start GRAY
  dist[s] = 0;
  q.push(s);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : adj[u]) {
      if (color[v] == 0) {     // WHITE → undiscovered
        color[v] = 1;          // GRAY → discovered
        dist[v] = dist[u] + 1; // shortest distance update
        parent[v] = u;
        q.push(v);
      }
    }

    color[u] = 2; // BLACK → fully processed
  }

  // 출력 (옵션)
  for (int i = 0; i < n; i++) {
    cout << "node " << i << " dist = " << dist[i] << " parent = " << parent[i]
         << "\n";
  }
}

int main() {
  // 예시 그래프 (0-based)
  vector<vector<int>> graph = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};

  BFS(graph, 0);
}
