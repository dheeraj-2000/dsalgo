#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#Question link - https://practice.geeksforgeeks.org/problems/middle-of-three2926/1
def middle(self,A,B,C):
        if A<B:
            return B if B<C else max(A,C)
        return A if A<C else max(B,C)

