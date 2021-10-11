#include <bits/stdc++.h>
using namespace std;
class Solution
{
    void helper(int i, int j, vector<vector<int>> &m, int n, vector<string> &ans, string move,
                vector<vector<int>> &vis, int di[], int dj[])
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(move);
            return;
        }
        string s = "DLRU";
        for (int ind = 0; ind < 4; ind++)
        {
            int i_next = i + di[ind];
            int j_next = j + dj[ind];
            if (i_next >= 0 && j_next >= 0 && i_next < n && j_next < n && !vis[i_next][j_next] && m[i_next][j_next] == 1)
            {
                vis[i][j] = 1;
                helper(i_next, j_next, m, n, ans, move + s[ind], vis, di, dj);
                vis[i][j] = 0;
            }
        }
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int di[] = {+1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        vector<string> ans;
        if (m[0][0] == 1)
        {
            helper(0, 0, m, n, ans, "", vis, di, dj);
        }
        return ans;
    }
};