#include <bits/stdc++.h>
using namespace std;

// Recursive function that prints the optimal parenthesization
void PrintOptimalParens(const vector<vector<int>> &S, int i, int j) {
  if (i == j) {
    cout << "A" << i; // base case: single matrix
  } else {
    cout << "(";
    PrintOptimalParens(S, i, S[i][j]);     // print left subchain
    PrintOptimalParens(S, S[i][j] + 1, j); // print right subchain
    cout << ")";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector<long long> row(N + 1), col(N + 1);
  for (int i = 1; i <= N; ++i) {
    long long r, c;
    cin >> r >> c;
    row[i] = r;
    col[i] = c;
  }

  const long long INF = 1e18;
  vector<vector<long long>> DP(N + 1, vector<long long>(N + 1, 0));
  vector<vector<int>> S(N + 1, vector<int>(N + 1, 0)); // store split indices

  // Step 1: cost is 0 when multiplying one matrix
  for (int i = 1; i <= N; ++i)
    DP[i][i] = 0;

  // Step 2: compute for chain lengths l = 2 to N
  for (int l = 2; l <= N; ++l) {
    for (int i = 1; i <= N - l + 1; ++i) {
      int j = i + l - 1;
      DP[i][j] = INF;

      // Step 3: find best split position
      for (int k = i; k <= j - 1; ++k) {
        long long q = DP[i][k] + DP[k + 1][j] + row[i] * col[k] * col[j];
        if (q < DP[i][j]) {
          DP[i][j] = q;
          S[i][j] = k; // remember the split index
        }
      }
    }
  }

  // Output results
  cout << "Minimum multiplication cost: " << DP[1][N] << '\n';
  cout << "Optimal parenthesization: ";
  PrintOptimalParens(S, 1, N);
  cout << '\n';

  return 0;
}
