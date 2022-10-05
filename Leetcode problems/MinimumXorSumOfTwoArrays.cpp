// https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/
// Minimum XOR Sum of Two Arrays
// You are given two integer arrays nums1 and nums2 of length n.

// The XOR sum of the two integer arrays is (nums1[0] XOR nums2[0]) + (nums1[1] XOR nums2[1]) + ... + (nums1[n - 1] XOR nums2[n - 1]) (0-indexed).
// For example, the XOR sum of [1,2,3] and [3,2,1] is equal to (1 XOR 3) + (2 XOR 2) + (3 XOR 1) = 2 + 0 + 2 = 4.
// Rearrange the elements of nums2 such that the resulting XOR sum is minimized.
// Return the XOR sum after the rearrangement.

// Example 1:

// Input: nums1 = [1,2], nums2 = [2,3]
// Output: 2
// Explanation: Rearrange nums2 so that it becomes [3,2].
// The XOR sum is (1 XOR 3) + (2 XOR 2) = 2 + 0 = 2.

// Constraints:
// n == nums1.length
// n == nums2.length
// 1 <= n <= 14
// 0 <= nums1[i], nums2[i] <= 107

// Approach 1: Brute Force

// Intuition and Algorithm
// We can try all possible permutations of nums2 and find the minimum XOR sum.

// Complexity Analysis with brute force
// Time complexity : O(n!). There are n! permutations of nums2.
// Space complexity : O(n). The depth of the recursion tree can go upto n.

// Solution using brute force

class Solution
{
public:
    int minXorSum(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<int> perm(n);
        for (int i = 0; i < n; i++)
            perm[i] = i;
        int ans = INT_MAX;
        do
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += nums1[i] ^ nums2[perm[i]];
            }
            ans = min(ans, sum);
        } while (next_permutation(perm.begin(), perm.end()));
        return ans;
    }
};

// Approach 2: Dynamic Programming

// Intuition and Algorithm
// We can use dynamic programming to solve this problem.
// Let dp[mask] be the minimum XOR sum of nums2 with the elements of nums1 that are not used yet.
// We can use a bitmask to represent the elements of nums1 that are not used yet.
// For example, if mask = 1010, then nums1[1] and nums1[3] are not used yet.
// We can iterate over all the elements of nums2 that are not used yet and find the minimum XOR sum.

// Complexity Analysis with dynamic programming
// Time complexity : O(n^2×2^n). There are 2^n possible masks and for each mask, we iterate over all the elements of nums2.
// Space complexity : O(2^n). dp array of size 2n is used.

// Solution using dynamic programming

class Solution
{
public:
    int dp[14][1 << 14]; // dp[mask][i] = minimum XOR sum of nums2 with the elements of nums1 that are not used yet
    int solve(vector<int> &nums1, vector<int> &nums2, int i, int used)
    {
        if (i == nums1.size()) // if all elements of nums1 are used
            return 0;
        if (dp[i][used] != -1) // if already calculated
            return dp[i][used];
        int ans = INT_MAX;
        for (int j = 0; j < nums2.size(); j++) 
        {
            if (((used >> j) & 1) == 0) // if nums2[j] is not used yet
            {
                used ^= (1 << j); // mark nums2[j] as used
                ans = min(ans, (nums1[i] ^ nums2[j]) + solve(nums1, nums2, i + 1, used)); // find minimum XOR sum
                used ^= (1 << j); // mark nums2[j] as not used
            }
        }
        return dp[i][used] = ans; // store the result
    }
    int minimumXORSum(vector<int> &nums1, vector<int> &nums2)
    {
        int used = 0;
        memset(dp, -1, sizeof(dp));
        return solve(nums1, nums2, 0, used);
    }
};