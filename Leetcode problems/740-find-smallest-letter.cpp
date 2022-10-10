//leetcode
//740
//Find Smallest Letter Greater Than Target


class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int start =0;
        int end=letters.size()-1;
        
       
        
        while(start<=end)
        {
            int mid= start+(end-start)/2;
            if(target< letters[mid])
                end= mid-1;
            else
                start=mid+1;
            
                
        }
        return letters[start%letters.size()];
        
    }
};