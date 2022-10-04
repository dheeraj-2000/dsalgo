//leetcode
//162
//Find peak element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
         int start=0;
        int end=nums.size()-1;
        while(start<end)
        {
            int mid= start+(end-start)/2;
            if(nums[mid]>nums[mid+1])     //search in left
                end=mid;
            else  if(nums[mid]<nums[mid+1])     //search in right
                start=mid+1;
           
           
        }
          return start;
       
    }
        
    
};