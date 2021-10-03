// Link to Question https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

//Time complexity is O(k*2^n) since for each k, we try to find a possible subset which adds to the required sum. While some subsets will not be explored since they have already been visited, 2^n will still be an upper bound in the worst case. 

class Solution {
public:
    int count=0;
    vector<int> vis;
    bool choose(vector<int> &nums, int idx, int target, int k, int curr)
    {
        if(curr>target)
            return false;
        if(k==1)
            return true;
        if(curr==target)
        {
            return choose(nums, 0, target, k-1, 0);
        }
        for(int i=idx;i<nums.size();i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                if(choose(nums,i+1,target,k, curr+nums[i]))
                    return true;
                vis[i]=0;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size(), sum=0;
        vis.resize(n);
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum%k!=0)
            return false;
        sum/=k;
        return choose(nums, 0, sum, k, 0);
    }
};