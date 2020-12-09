#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#code
#Question link - https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one/0
def rotate(li):
    temp = li[-1]
    for i in range(len(li)-1,-1,-1):
        li[i] = li[i-1]
    li[0] = temp
    return li
    
num_of_tests = int(input())
for i in range(num_of_tests):
    n = int(input())
    li = [int(ele) for ele in input().split()]
    ans = rotate(li)
    for ele in ans:
        print(ele, end=' ')
    print()

