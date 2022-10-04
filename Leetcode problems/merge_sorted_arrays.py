class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        if not nums1:
            return nums2
        if not nums2:
            return nums1
        for i in range(m):
            if nums1[i]>nums2[0]: # first element of nums1 is greater than first element of nums2
                nums1[i],nums2[0]=nums2[0],nums1[i] #swap the first element of both the arrays
            temp=nums2[0]
            k=1
            while k<n and nums2[k]<temp: # make nums2 sorted again by sending the first element at the correct position
                nums2[k-1]=nums2[k]
                k+=1
            nums2[k-1]=temp
        j=0
        for i in range(m,m+n):# insert the remaining elements of nums2
            nums1[i]=nums2[j]
            j+=1 
