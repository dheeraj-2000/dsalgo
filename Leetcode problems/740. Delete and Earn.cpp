class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size(); 
        int m = *max_element(nums.begin(), nums.end()); // max element in nums array
        vector<int> count(m+1), dp(m+1);
        
        for(int i = 0; i < n; i++){
            count[nums[i]] += nums[i];
        }
        dp[0] = count[0];
        dp[1] = max(count[0], count[1]);
        for(int i = 2; i <= m; i++){
            dp[i] = max(dp[i-1], count[i]+dp[i-2]);
        }
        return dp[m];
    }
};
// store count of all the element then apply house robber algo on count array
// 1, 2, 3, 1, 1
// [0, 3, 1, 1] count of element
// [0, 3, 2, 3] // multiplying element with count, Then apply bank robber algo;
