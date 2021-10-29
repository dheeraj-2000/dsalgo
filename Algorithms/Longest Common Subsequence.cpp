class Solution
{

public:
    int lcs(string &x, int i, string &y, int j, vector<vector<int>> &memo)
    {
        if (i == x.length() || j == y.length())
            return 0;

        if (memo[i][j] != -1)
            return memo[i][j];

        if (x[i] == y[j])
        {
            memo[i][j] = 1 + lcs(x, i + 1, y, j + 1, memo);
            return memo[i][j];
        }

        memo[i][j] = max(lcs(x, i, y, j + 1, memo), lcs(x, i + 1, y, j, memo));

        return memo[i][j];
    }

    int longestCommonSubsequence(string text1, string text2)
    {

        int n = 1005;
        vector<vector<int>> memo(n, vector<int>(n, -1));

        int ans = lcs(text1, 0, text2, 0, memo);

        return ans;
    }
};