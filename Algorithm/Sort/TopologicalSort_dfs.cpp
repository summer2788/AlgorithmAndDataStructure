#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
  Graph(int n) : n(n), adj(n), state(n, 0), hasCycle(false) {}

  void addEdge(int u, int v) { adj[u].push_back(v); }

  void topologicalSort() {
    // run DFS from every node
    for (int i = 0; i < n; i++) {
      if (state[i] == 0) // 0 = unvisited
      {
        dfs(i);
        if (hasCycle) // early stop if you want
          break;
      }
    }

    if (hasCycle) {
      cout << "Graph has a cycle. Topological sort is not possible.\n";
      return;
    }

    reverse(result.begin(), result.end());
    for (int i : result) {
      cout << i << " ";
    }
    cout << endl;
  }

private:
  void dfs(int u) {
    state[u] = 1; // 1 = visiting (gray)

    for (int v : adj[u]) {
      if (state[v] == 0) {
        dfs(v);
        if (hasCycle)
          return; // propagate early exit
      } else if (state[v] == 1) {
        // edge u -> v, and v is in current recursion stack
        // => back edge => cycle exists
        hasCycle = true;
        return;
      }
    }

    state[u] = 2; // 2 = done (black)
    result.push_back(u);
  }

  int n;
  vector<vector<int>> adj;
  vector<int> state; // 0 = unvisited, 1 = visiting, 2 = done
  vector<int> result;
  bool hasCycle;
};

int main() {
  Graph g(6);
  g.addEdge(5, 2);
  g.addEdge(5, 0);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(2, 3);
  g.addEdge(3, 1);

  // Try adding a cycle like: g.addEdge(1, 5);
  g.topologicalSort();
  return 0;
}
