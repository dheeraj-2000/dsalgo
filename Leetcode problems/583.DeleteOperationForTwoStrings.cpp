
class Solution {
public:
  int dp[505][505];

  int lcs(int i, int j, string &s1, string &s2) {

    if (i < 0 || j < 0) {
      return 0;
    }
    if (dp[i][j] != -1) {
      return dp[i][j];
    }

    int ans = INT_MIN;

    ans = max(ans, lcs(i, j - 1, s1, s2));
    ans = max(ans, lcs(i - 1, j, s1, s2));
    ans = max(ans, lcs(i - 1, j - 1, s1, s2) + (s1[i] == s2[j]));

    return dp[i][j] = ans;
  }

  int minDistance(string word1, string word2) {
    memset(dp, -1, sizeof(dp));
    int s1 = word1.size();
    int s2 = word2.size();

    int l = lcs(s1 - 1, s2 - 1, word1, word2);
    // std::cout << "lcs is " << l << std::endl;

    return s1 - l + s2 - l;
  }
};
