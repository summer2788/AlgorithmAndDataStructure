// 그래프 구조에 대한 중요한 정보들 제공
// discovery time 과 finish time 은 parenthesis 구조 제공, 조상 자식 , 판별에
// 유용 directed graph 에서 black edge 가 없다면 acyclic 구조인 것을 알 수 있다.
// undirected graph 에서는 모든 edge 가 tree edge 아니면 black edge 이다.

#include <bits/stdc++.h>
using namespace std;

vector<int> color; // 0: WHITE, 1: GRAY, 2: BLACK
vector<int> parent;
vector<int> d, f;
int Time = 0;

void DFS_Visit(const vector<vector<int>> &adj, int u) {
  Time++;
  d[u] = Time;
  color[u] = 1; // GRAY

  for (int v : adj[u]) {
    if (color[v] == 0) { // WHITE
      parent[v] = u;
      DFS_Visit(adj, v);
    }
  }

  Time++;
  f[u] = Time;
  color[u] = 2; // BLACK
}

void DFS(const vector<vector<int>> &adj) {
  int n = adj.size();
  color.assign(n, 0);
  parent.assign(n, -1);
  d.assign(n, 0);
  f.assign(n, 0);

  Time = 0;

  for (int u = 0; u < n; u++) {
    if (color[u] == 0)
      DFS_Visit(adj, u);
  }
}

int main() {
  // 예시 그래프
  vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};

  DFS(graph);

  for (int i = 0; i < graph.size(); i++) {
    cout << "node " << i << " d=" << d[i] << " f=" << f[i]
         << " parent=" << parent[i] << "\n";
  }
}
