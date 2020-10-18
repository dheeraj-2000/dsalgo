//Problem link: https://leetcode.com/problems/rotate-array/
//Given an array, rotate the array to the right by k steps, where k is non-negative.


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int len = nums.size(); //finding length of vector nums
        vector<int> temp(len); //using an external temp array to store values
        for(int i = 0; i<len; i++)
            temp[(i+k)%len] = nums[i];
        for(int i = 0; i<len; i++)
            nums[i] = temp[i];
    }
};
