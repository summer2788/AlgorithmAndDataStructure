#include <bits/stdc++.h>
using namespace std;

int kadane(const vector<int> &a) {
  int n = a.size();
  if (n == 0)
    return 0; // 문제 정의에 따라 다르게 처리 가능

  int current_sum = a[0];
  int best_sum = a[0];

  for (int i = 1; i < n; ++i) {
    // i에서 끝나는 최대 연속합
    current_sum = max(a[i], current_sum + a[i]);
    // 전체 최대값 갱신
    best_sum = max(best_sum, current_sum);
  }
  return best_sum;
}

int main() {
  vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << kadane(a) << "\n"; // 출력: 6
  return 0;
}
