#House Robber
#Link to Problem :- https://leetcode.com/problems/house-robber/

int rob(vector<int>& nums) {
        int n = nums.size(),maxl=0;
        if(n<=0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        vector<int> dp(n,0);
        dp[0]=nums[0];
        dp[1] = nums[1];
        maxl = max(dp[0],dp[1]);
        for(int i=2;i<n;i++){
            if(i!=2)
                dp[i] = max(dp[i-2] + nums[i],dp[i-3]+nums[i]);
            else 
                dp[i] = dp[i-2]+nums[i];
            if(dp[i]>maxl){
                maxl = dp[i];
            }
        }
        return maxl;
    }
