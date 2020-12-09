#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#code
#Question link - https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0
def Sort012(li):
    li.sort()
    return li

num_of_test_case = int(input())
for i in range(num_of_test_case):
    n = int(input())
    li = [int(ele) for ele in input().split()]
    ans = Sort012(li)
    for ele in ans:
        print(ele, end=" ")
    print()

