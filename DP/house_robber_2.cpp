class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
		// dp1 -> 1 to n-1
		// dp2 -> 2 to n
		
        int dp1[n], dp2[n];
		
		// if we have robbed the first house, then we can't rob the second house
        dp1[0] = nums[0];
        dp1[1] = nums[0];
		
		// if we didn't rob the first house, we will definetely rob the second
        dp2[0] = 0;
        dp2[1] = nums[1];
        
        for(int i = 2; i < n; i++) {
		
			// make optimal choice at each house
            dp1[i] = max(nums[i] + dp1[i-2], dp1[i-1]);
            dp2[i] = max(nums[i] + dp2[i-2], dp2[i-1]);
        }
        
		// dp1 is for nums[1 - (n-1)] so we won't consider the last house in this case and dp1[n-2] will be max profit
		// and dp2 is for nums[2 - n] so we can take the last house
        return max(dp1[n-2], dp2[n-1]);
    }
};
