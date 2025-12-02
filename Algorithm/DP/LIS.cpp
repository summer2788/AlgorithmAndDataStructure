int n = nums.size();
vector<int> tails;         // 값
vector<int> pos;           // 각 길이의 마지막 원소 인덱스
vector<int> parent(n, -1); // 각 원소의 이전 원소 인덱스

for (int i = 0; i < n; ++i) {
  int x = nums[i];
  int idx = lower_bound(tails.begin(), tails.end(), x) - tails.begin();

  if (idx == (int)tails.size()) {
    tails.push_back(x);
    pos.push_back(i);
  } else {
    tails[idx] = x;
    pos[idx] = i;
  }

  if (idx > 0) {
    parent[i] = pos[idx - 1]; // 나보다 한 단계 짧은 LIS의 마지막 인덱스
  }
}

// tails.size() 가 LIS 길이
int len = tails.size();
vector<int> lis(len);
int cur = pos[len - 1]; // 마지막 원소 인덱스

for (int k = len - 1; k >= 0; --k) {
  lis[k] = nums[cur];
  cur = parent[cur];
}
