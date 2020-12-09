#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#Question link - https://leetcode.com/problems/search-a-2d-matrix/
class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix:
            return False
        
        m = len(matrix)
        n = len(matrix[0])
        
        for i in range(m):
            for j in range(n):
                if matrix[i][j]>target:
                    continue
                if matrix[i][j] == target:
                    return True
                
        return False

