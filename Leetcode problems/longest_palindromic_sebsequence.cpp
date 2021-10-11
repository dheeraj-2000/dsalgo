/*
Leetcode 516 - Longest Palindromic Subsequence
Link - https://leetcode.com/problems/longest-palindromic-subsequence/

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <climits>
#include <functional>

using namespace std;

int longestPalindromeSubseq(string &s, int i, int j, vector<vector<int>> &dp)
{
    if(i>=j)
        return dp[i][j] = (i==j ? 1 : 0);
    
    if(dp[i][j]!=0)
        return dp[i][j];
    if(s[i]==s[j])
    {
        return dp[i][j]=longestPalindromeSubseq(s,i+1, j-1, dp)+2;
    }
    else
        return dp[i][j] = max(longestPalindromeSubseq(s,i+1, j, dp),longestPalindromeSubseq(s,i, j-1, dp));
}

int main()
{
	string s = "bbbab";
	int n = s.length();
    vector<vector<int>> dp(n, (vector<int>(n,0)));
    cout<<"The length of longest palindromic subsequence in "<<s<<" is "<<longestPalindromeSubseq(s,0,n-1,dp);
	return 0;
}