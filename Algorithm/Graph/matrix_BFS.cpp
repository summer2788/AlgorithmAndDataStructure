int matrixBFS(const vector<vector<int>> &grid, int sr, int sc) {
  int ROWS = grid.size();
  int COLS = grid[0].size();
  vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

  queue<pair<int, int>> q;
  q.push({sr, sc});
  visited[sr][sc] = true;

  vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int steps = 0;

  while (!q.empty()) {
    int size = q.size();
    while (size--) {
      auto [r, c] = q.front();
      q.pop();

      // 도착 조건(문제에 따라 바뀔 수 있음)
      if (grid[r][c] == 0)
        return steps;

      for (auto &d : dirs) {
        int nr = r + d[0], nc = c + d[1];
        if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && !visited[nr][nc] &&
            grid[nr][nc] != -1) {
          visited[nr][nc] = true;
          q.push({nr, nc});
        }
      }
    }
    steps++;
  }
  return INT_MAX; // reachable X
}
