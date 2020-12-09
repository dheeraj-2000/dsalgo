#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#Question link - https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/0
class Solution:
    def median(self, matrix, r, c):
        arr = []
        if not matrix:
            return
        for i in range(r):
            for j in range(c):
                arr.append(matrix[i][j])
        arr.sort()
        mid = len(arr)//2
        return arr[mid]
        #code here 



#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    ob = Solution()
    t = int (input ())
    for _ in range (t):
        r,c = map(int,input().strip().split())
        matrix = [[0 for j in range(c)] for i in range(r)]
        line1 = [int(x) for x in input().strip().split()]       
        k = 0
        for i in range(r):
            for j in range (c):
                matrix[i][j]=line1[k]
                k+=1
        ans = ob.median(matrix, r, c);
        print(ans)
# } Driver Code Ends

