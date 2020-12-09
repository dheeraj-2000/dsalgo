#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#code
#Question link - https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix/0
import numpy as np

def SpiralTraversing(matrix, n, m):
    
    top = 0
    left = 0
    bottom = n-1
    right = m-1
    counter = 0
    while top<=bottom and left<=right:
        if counter == 0:
            for i in range(left, right+1):
                print(arr[top][i], end=" ")
            top += 1
        
        elif counter == 1:
            for i in range(top, bottom+1):
                print(arr[i][right], end=" ")
            right -= 1
        
        elif counter == 2:
            for i in range(right, left-1, -1):
                print(arr[bottom][i], end=" ")
            bottom -= 1
            
        elif counter == 3:
            for i in range(bottom, top-1, -1):
                print(arr[i][left], end=" ")
            left -= 1
    
        counter = (counter+1)%4
    
    
    #if not matrix: return
        
    # sr, sc, er, ec = 0, 0, len(arr)-1, len(arr[0])-1
    # direction = 0
    # res = []
    
    # while sr<=er and sc<=ec:
    #     if direction == 0:
    #         for i in range(sc, ec+1):
    #             print(matrix[sr][i], end=" ")
    #         sr+=1
    #         direction = 1
    #     elif direction == 1:
    #         for i in range(sr, er+1):
    #             print(matrix[i][ec], end=" ")
    #         ec-=1
    #         direction = 2
    #     elif direction == 2:
    #         for i in range(ec, sc-1, -1):
    #             print(matrix[er][i], end=" ")
    #         er-=1
    #         direction = 3
    #     else:
    #         for i in range(er, sr-1, -1):
    #             print(matrix[i][sc], end=" ")
    #         sc+=1
    #         direction = 0


num_of_tests = int(input())
for i in range(num_of_tests):
    n, m = map(int, input().split())
    entries = list(map(int, input().split())) 
    arr = np.array(entries).reshape(n, m)
    SpiralTraversing(arr, n, m)

