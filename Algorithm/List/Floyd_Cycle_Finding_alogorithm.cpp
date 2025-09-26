// Floyd’s Cycle Finding Algorithm
// leet code 287. Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/description/

int findDuplicate(vector<int> &nums) {
  int fast = nums[0];
  int slow = nums[0];

  slow = nums[slow];
  fast = nums[nums[fast]];

  while (slow != fast) {
    slow = nums[slow];
    fast = nums[nums[fast]];
  }

  slow = nums[0];

  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }

  return slow;
}
