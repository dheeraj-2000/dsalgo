#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#code
#Question link - https://practice.geeksforgeeks.org/problems/union-of-two-arrays/0
def UnionOf2Arrays(li1, li2):
    d1 = {}
    d2 = {}
    for ele in li1:
        d1[ele] = d1.get(ele, 0) + 1
    for ele in li2:
        d2[ele] = d2.get(ele, 0) + 1
    length = len(d1)
    for ele in d2:
        if ele not in d1:
            length += 1
    return length
    
    
num_of_test_cases = int(input())
for i in range(num_of_test_cases):
    a, b = input().split()
    li1 = [int(ele) for ele in input().split()]
    li2 = [int(ele) for ele in input().split()]
    print(UnionOf2Arrays(li1, li2))

