class DSU {
  vector<int> Parent, Size;

public:
  DSU(int n) {
    Parent.resize(n);
    Size.resize(n);
    for (int i = 0; i < n; i++) {
      Parent[i] = i;
      Size[i] = 1;
    }
  }

  int find(int node) {
    if (Parent[node] != node) {
      Parent[node] = find(Parent[node]);
    }
    return Parent[node];
  }

  bool unionNodes(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv)
      return false;
    if (Size[pu] >= Size[pv]) {
      Size[pu] += Size[pv];
      Parent[pv] = pu;
    } else {
      Size[pv] += Size[pu];
      Parent[pu] = pv;
    }
    return true;
  }

  bool connected(int u, int v) { return find(u) == find(v); }
};
