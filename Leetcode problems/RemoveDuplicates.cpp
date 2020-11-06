//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=1;
        int n = nums.size();
        if(n==0)
            return 0;
        for(j=1;j<n;j++)
        {
            if(nums[i] != nums[j])
            {
               i++;
               nums[i] = nums[j];
            }
        }
        return (i+1);
    }
};
