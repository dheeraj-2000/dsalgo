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
