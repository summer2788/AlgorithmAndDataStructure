void matrixDFS(const vector<vector<int>> &grid, vector<vector<bool>> &visited,
               int r, int c) {
  int ROWS = grid.size();
  int COLS = grid[0].size();

  visited[r][c] = true;

  vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  for (auto &d : dirs) {
    int nr = r + d[0];
    int nc = c + d[1];

    if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && !visited[nr][nc] &&
        grid[nr][nc] != -1) {
      matrixDFS(grid, visited, nr, nc);
    }
  }
}
