class Solution {
public:
  int dp[2100][2100];

  int frogJump(int pos, int k, int n, vector<int> &stones) {

    if (pos == n - 1) {
      return true;
    }
    if (dp[pos][k] != -1) {
      return dp[pos][k];
    }

    int ja = false, jb = false, jc = false;

    int x = -1;
    if (k - 1 > 0) {
      x = stones[pos] + k - 1;
      int i = lower_bound(stones.begin(), stones.end(), x) - stones.begin();
      if (i != n) {
        if (stones[i] == x)
          ja = frogJump(i, k - 1, n, stones);
      }
    }

    x = stones[pos] + k;
    int i = lower_bound(stones.begin(), stones.end(), x) - stones.begin();
    if (i != n) {
      if (stones[i] == x)
        jb = frogJump(i, k, n, stones);
    }

    x = stones[pos] + k + 1;
    i = lower_bound(stones.begin(), stones.end(), x) - stones.begin();
    if (i != n) {
      if (stones[i] == x)
        jc = frogJump(i, k + 1, n, stones);
    }

    return dp[pos][k] = ja || jb || jc;
  }

  bool canCross(vector<int> &stones) {
    if (stones[1] - stones[0] != 1)
      return false;
    memset(dp, -1, sizeof(dp));
    int n = stones.size();
    return frogJump(1, 1, n, stones);
  }
};
