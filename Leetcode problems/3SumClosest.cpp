// problem: https://leetcode.com/problems/3sum-closest/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int mini=INT_MAX;
        int ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int l=i+1,r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(abs(sum-target)<mini){
                    mini=abs(target-sum);
                    ans=sum;
                }
            
                if(sum==target)
                    return sum;
                else if(sum<target)
                    l++;
                else
                    r--;
            }
        }
        return ans;
    }
};