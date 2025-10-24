#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>> &graph) {
  vector<bool> visited(graph.size(), false);
  queue<int> q;
  q.push(start);
  visited[start] = true;

  int depth = 0; // 현재 레벨 (depth)
  while (!q.empty()) {
    int sz = q.size(); // 현재 레벨의 노드 수

    cout << "Depth " << depth << ": ";
    for (int i = 0; i < sz; ++i) {
      int cur = q.front();
      q.pop();
      cout << cur << " ";

      // 다음 레벨의 자식 노드들 enqueue
      for (int nxt : graph[cur]) {
        if (!visited[nxt]) {
          visited[nxt] = true;
          q.push(nxt);
        }
      }
    }
    cout << "\n";
    depth++; // 다음 레벨로 이동
  }
}

int main() {
  int n = 6;
  vector<vector<int>> graph = {
      {},     // 0 (dummy)
      {2, 3}, // 1
      {4, 5}, // 2
      {6},    // 3
      {},     // 4
      {},     // 5
      {}      // 6
  };

  bfs(1, graph);
  return 0;
}
