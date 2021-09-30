#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#code
#Question link - https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
def Cont_Sub_Array(li):
    curr_max = li[0]
    global_max = li[0]
    for curr in li[1::]:
        curr_max = curr_max + curr
        if curr>curr_max:
            curr_max = curr
        if curr_max >= global_max:
            global_max = curr_max
    return global_max
    
    
total_test_cases = int(input())
for i in range(total_test_cases):
    no_of_inputs = int(input())
    li = [int(ele) for ele in input().split()]
    print(Cont_Sub_Array(li))

