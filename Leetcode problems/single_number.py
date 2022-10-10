'''
LeetCode 136
https://leetcode.com/problems/single-number/

Given a non-empty array of integers nums, every element 
appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity 
and use only constant extra space.
Example 1:

Input: nums = [2,2,1]
Output: 1

Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
'''
'''
61 / 61 test cases passed.
Status: Accepted
Runtime: 245 ms
Memory Usage: 15.7 MB

LOGIC:- 
The idea is to use set() to find the unique numbers, 
then make a sum and times 2. 
Finally, substract the sum of the original list. 
Every integer exists 2 times except one. So the answer is quite obvious.
'''
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        x = set(nums)
        return sum(x) * 2 - sum(nums)

