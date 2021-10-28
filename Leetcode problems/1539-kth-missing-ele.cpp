//leetcode
//1539
//kth missing element

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s=0,e=arr.size()-1,m;
        while(s<=e)
        {
            m=s+(e-s)/2;
            if((arr[m]-(m+1))>=k)
              e=m-1;
            else
             s=m+1;          }
        return s+k;
        
    }
};