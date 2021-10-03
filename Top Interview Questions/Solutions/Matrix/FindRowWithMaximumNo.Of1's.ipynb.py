#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#User function Template for python3
#Question link - https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1
class Solution:

	def rowWithMax1s(self,arr, n, m):
	    if not arr:
	        return -1
	    counter = 0
	    max_counter = 0
	    index = 0
	    for i in range(n):
	        for j in range(m-1, -1, -1):
	            if arr[i][j] == 1:
	                counter += 1
	            else:
	                continue
	        if max_counter<counter:
	            max_counter = counter
	            index = i
	        counter = 0
	    if max_counter == 0:
	        return -1
	    return index
		# code here



#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n, m = list(map(int, input().strip().split()))
        
        inputLine = list(map(int, input().strip().split()))
        arr = [[0 for j in range(m)] for i in range(n)]
        
        for i in range(n):
            for j in range(m):
                arr[i][j] = inputLine[i * m + j]
        ob = Solution()
        ans = ob.rowWithMax1s(arr, n, m)
        print(ans)
        tc -= 1

# } Driver Code Ends

