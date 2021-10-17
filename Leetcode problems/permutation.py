'''
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

'''
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        
        
        if len(s1)>len(s2):
            return False
        a = [0]*26
        b = [0]*26
        for i in range(len(s1)):
            
            a[ord(s1[i])-ord('a')]+=1
            b[ord(s2[i])-ord('a')]+=1
            
            
        for i in range(len(s2)-len(s1)):
            if a==b:
                return True
            b[ord(s2[i+len(s1)])-97]+=1
            b[ord(s2[i])-97]-=1
            
        print(a)
        print(b)
        return a==b
