class Solution {
public:
  int dp[205][20005];

  bool subsetSum(int ind, int sum, vector<int> &nums) {

    if (sum == 0) {
      return true;
    }
    if (ind < 0) {
      return false;
    }

    if (sum < 0) {
      return false;
    }

    if (dp[ind][sum] != -1) {
      return dp[ind][sum];
    }

    return dp[ind][sum] = subsetSum(ind - 1, sum, nums) ||
                          subsetSum(ind - 1, sum - nums[ind], nums);
  }

  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1) {
      return false;
    }

    memset(dp, -1, sizeof(dp));

    return subsetSum(nums.size() - 1, sum / 2, nums);
  }
};
