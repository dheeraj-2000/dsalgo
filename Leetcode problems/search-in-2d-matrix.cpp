//problem link:- https://leetcode.com/problems/search-a-2d-matrix/
class Solution {
public:
    int binary_Search(vector<vector<int>>&matrix,int target,int start,int end)
    {
        int mid;
        if(start <= end)
        {    mid = (start+end)/2;

         if(matrix[mid/matrix[0].size()][mid%matrix[0].size()] == target)
             return 1;
         else if(target < matrix[mid/matrix[0].size()][mid%matrix[0].size()])
             return binary_Search(matrix,target,start,mid-1);
         else
             return binary_Search(matrix,target,mid+1,end);
        }
        else
            return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int start = 0 ;
        int end = matrix.size() * matrix[0].size() - 1;
        int search_ans = binary_Search(matrix,target,start,end);
        if(search_ans != -1)
            return true;
        else
            return false;
        }
};
