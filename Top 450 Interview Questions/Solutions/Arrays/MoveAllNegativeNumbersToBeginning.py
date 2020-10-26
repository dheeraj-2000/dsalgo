#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#code
#Question link - https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/
def NegetiveBeforePositive(li):
    i = 0
    j = len(li)-1
    
    while i<j:
        if li[i]<0:
            i+=1
        elif li[j]>0:
            j-=1
        if li[i]>0 and li[j]<0:
            li[i], li[j] = li[j], li[i]
    return li
    
li = [-12, 11, -13, -5, 6, -7, 5, -3, -6]
ans = NegetiveBeforePositive(li)
for ele in ans:
    print(ele, end=' ')

