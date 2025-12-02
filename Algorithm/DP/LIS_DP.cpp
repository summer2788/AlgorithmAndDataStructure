#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  pair<int, vector<int>> lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> LIS(n, 1);
    vector<int> parent(n, -1); // LIS 경로 복원을 위한 배열

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          if (LIS[i] < LIS[j] + 1) {
            LIS[i] = LIS[j] + 1;
            parent[i] = j; // j가 i의 이전 원소
          }
        }
      }
    }

    // 최장 LIS의 마지막 index 찾기
    int maxLen = 0;
    int lastIndex = 0;
    for (int i = 0; i < n; i++) {
      if (LIS[i] > maxLen) {
        maxLen = LIS[i];
        lastIndex = i;
      }
    }

    // parent 를 이용해 LIS 역추적
    vector<int> path;
    while (lastIndex != -1) {
      path.push_back(nums[lastIndex]);
      lastIndex = parent[lastIndex];
    }
    reverse(path.begin(), path.end());

    return {maxLen, path};
  }
};

int main() { Solution s{}; }
