// https://leetcode.com/problems/maximum-and-sum-of-array/
// Maximum and Sum of Array
// You are given an integer array nums of length n and an integer numSlots such that 2 * numSlots >= n. There are numSlots slots numbered from 1 to numSlots.
// You have to place all n integers into the slots such that each slot contains at most two numbers. The AND sum of a given placement is the sum of the bitwise AND of every number with its respective slot number.
// For example, the AND sum of placing the numbers [1, 3] into slot 1 and [4, 6] into slot 2 is equal to (1 AND 1) + (3 AND 1) + (4 AND 2) + (6 AND 2) = 1 + 1 + 0 + 2 = 4.
// Return the maximum possible AND sum of nums given numSlots slots.

// Example 1:
// Input: nums = [1,2,3,4,5,6], numSlots = 3
// Output: 9
// Explanation: One possible placement is [1, 4] into slot 1, [2, 6] into slot 2, and [3, 5] into slot 3. 
// This gives the maximum AND sum of (1 AND 1) + (4 AND 1) + (2 AND 2) + (6 AND 2) + (3 AND 3) + (5 AND 3) = 1 + 0 + 2 + 2 + 3 + 1 = 9.

// Constraints:
// n == nums.length
// 1 <= numSlots <= 9
// 1 <= n <= 2 * numSlots
// 1 <= nums[i] <= 15

// Approach 1: Brute Force
// Intuition and Algorithm
// We can try all possible placements of the numbers into the slots and find the maximum AND sum.
// Complexity Analysis with brute force
// Time complexity : O(n!). There are n! placements of the numbers into the slots.
// Space complexity : O(n). The depth of the recursion tree can go upto n.

// Solution using brute force
class Solution
{
public:
    int maxAndSum(vector<int> &nums, int numSlots)
    {
        int n = nums.size();
        vector<int> perm(n);
        for (int i = 0; i < n; i++)
            perm[i] = i; // 0, 1, 2, 3, 4, 5
        int ans = INT_MIN;
        do 
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += nums[i] & (perm[i] + 1);
            }
            ans = max(ans, sum);
        } while (next_permutation(perm.begin(), perm.end())); 
        return ans;
    }
};

// Approach 2: Dynamic Programming
// Intuition and Algorithm
// We can use dynamic programming to solve this problem.
// We can use dp[i][j] to represent the maximum AND sum of the first i numbers placed into j slots.

// Complexity Analysis with dynamic programming
// Time complexity : O(n^2). There are n^2 states in the dp array.
// Space complexity : O(n^2). The dp array of size n^2 is used.

// Solution using dynamic programming

class Solution {
public:
    int dp[18][1<<9][1<<9]; // dp[i][j][k] = maximum AND sum of first i numbers placed into j slots, where the last number is placed in the kth slot
    int slots;
    int solve(vector<int> &nums, int i, int used1, int used2){
        if(i==nums.size()) return 0; // base case
        if(dp[i][used1][used2]!=-1) return dp[i][used1][used2]; // if already calculated
        int ans= INT_MIN;
        for(int j=0; j<slots;j++)
        {
            if(((used1>>j) & 1)==0){ // if jth slot is not used
                used1^=(1<<j); // mark jth slot as used
                ans=max(ans, (nums[i]&(j+1))+solve(nums, i+1, used1, used2)); // place ith number in jth slot and recurse for next number
                used1^=(1<<j); // unmark jth slot
            }
            else if(((used2>>j) & 1)==0){ // if jth slot is used once
                used2^=(1<<j); // mark jth slot as used twice
                ans=max(ans, (nums[i]&(j+1))+solve(nums, i+1, used1, used2)); // place ith number in jth slot and recurse for next number
                used2^=(1<<j); // unmark jth slot
            }
        }
        return dp[i][used1][used2]=ans; // store the answer in dp array
    }
    int maximumANDSum(vector<int>& nums, int numSlots) {
        memset(dp,-1,sizeof(dp));  // initialize dp array with -1
        slots=numSlots;
        int used1=0, used2=0; // initially no slot is used
        return solve(nums, 0, used1, used2); 
    }
};