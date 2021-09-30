#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#code
#Question link - https://practice.geeksforgeeks.org/problems/kth-smallest-element/0
def kSmallestElement(li, k):
    li.sort()
    for i in range(len(li)-k):
        li.pop()
    if li[-1]:
        return li[-1]
    else:
        return None
    
num_of_test_cases = int(input())
for i in range(num_of_test_cases):
    n = int(input())
    li = [int(ele) for ele in input().split()]
    k = int(input())
    print(kSmallestElement(li, k))

