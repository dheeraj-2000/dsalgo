#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#code
# Link to question - https://practice.geeksforgeeks.org/problems/reverse-the-string/0
def reverse(li):
    for ele in li:
        print(ele[::-1])
        
numbers = int(input())
li = []
for i in range(numbers):
    ele = input()
    li.append(ele)
reverse(li)

