/*
You are given two 0-indexed integer arrays nums and multipliers of size n and m respectively, where n >= m.

You begin with a score of 0. You want to perform exactly m operations. On the ith operation (0-indexed) you will:

    Choose one integer x from either the start or the end of the array nums.
    Add multipliers[i] * x to your score.
        Note that multipliers[0] corresponds to the first operation, multipliers[1] to the second operation, and so on.
    Remove x from nums.

Return the maximum score after performing m operations.

Example 1:
Input: nums = [1,2,3], multipliers = [3,2,1]
Output: 14

Example 2:

Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
Output: 102
------------------------------------------------
Below is a Memoized version of the algorithm.
*/


class Solution {

    Integer[][] memoized;
    int[] num;
    int[] mul;
    public int maximumScore(int[] nums, int[] multipliers) {

        num=nums;
        mul=multipliers;
        int n=nums.length;
        int m=multipliers.length;

        memoized = new Integer[n][m];
        return memo(0,nums.length-1, 0);
    }

    int memo(int l, int r, int i){

        if(i==mul.length)
            return 0;
        // If already calculated, return the memoized value.
        if(memoized[l][i]!=null)
            return memoized[l][i];
        if(l<=r){
            // Maximum of wither the first element of nums or the last element of nums.
            memoized[l][i]=Math.max(mul[i] * num[l] + memo(l+1, r, i+1),
                                    mul[i] * num[r] + memo(l, r-1, i+1));
            return memoized[l][i];
        }
        else
            return 0;
    }
}
