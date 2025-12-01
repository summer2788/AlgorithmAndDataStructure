#include <bits/stdc++.h>
using namespace std;

// Build the DP table for LCS lengths.
vector<vector<int>> buildLCSdp(const string &A, const string &B) {
  int m = (int)A.size();
  int n = (int)B.size();

  // dp[i][j] = length of LCS of A[0..i-1], B[0..j-1]
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (A[i - 1] == B[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp;
}

// Reconstruct LCS string using the dp table (iterative backtracking).
string reconstructLCS(const string &A, const string &B,
                      const vector<vector<int>> &dp) {
  int r = (int)A.size();
  int c = (int)B.size();

  string result = "";

  // Follow the "gradient" of the dp table back to dp[0][0]
  // while the current cell still corresponds to a non-empty LCS.
  while (r > 0 && c > 0 && dp[r][c] > 0) {
    if (dp[r][c] == dp[r][c - 1]) {
      // Moving left: character B[c-1] not used in LCS
      c = c - 1;
    } else if (dp[r][c] == dp[r - 1][c]) {
      // Moving up: character A[r-1] not used in LCS
      r = r - 1;
    } else {
      // Diagonal move: A[r-1] == B[c-1] is part of the LCS
      result += B[c - 1]; // or A[r - 1], they are equal
      r = r - 1;
      c = c - 1;
    }
  }

  reverse(result.begin(), result.end());
  return result;
}

int main() {
  string A = "ABCBDAB";
  string B = "BDCABA";

  auto dp = buildLCSdp(A, B);
  string lcs = reconstructLCS(A, B, dp);

  cout << "Length of LCS: " << dp[A.size()][B.size()] << "\n";
  cout << "LCS: " << lcs << "\n";

  return 0;
}
