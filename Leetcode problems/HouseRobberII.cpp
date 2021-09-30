// Problem link: https://leetcode.com/problems/house-robber-ii/
// You are a professional robber planning to rob houses along a street. 
// Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. 
// That means the first house is the neighbor of the last one. 
// Meanwhile, adjacent houses have a security system connected, and 
// it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers nums representing the amount of money of each house, 
// return the maximum amount of money you can rob tonight without alerting the police.

class Solution {
public:
    int helper(vector<int>& nums, int first, int last) {
        
        int prevHouse=0, prevHouseHouse=0, ans=0;
        for(int i=first; i<last; i++) {
            ans = max(prevHouse, prevHouseHouse+nums[i]);
            prevHouseHouse = prevHouse;
            prevHouse = ans;
        }
        return ans;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        return max(helper(nums, 0, nums.size()-1), helper(nums, 1, nums.size()));
    }
        
};
