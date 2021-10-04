/*
Link to problem: https://leetcode.com/problems/spiral-matrix/
Difficulty: Medium
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();        //number of rows
        int n=matrix[0].size();     //number of columns

        vector<int> res(m*n);       //result vector
        int resi=0;                 //index for "result" vector

        int i, j;                   //loop variables to traverse through 2-D vector "matrix"
        for(i=0; i<m; i++)          
        {
            if(resi==m*n)
                break;

            j=i;
            for(; j<n-i && resi!=m*n; j++)              //traversing upper row left to right
            {
                res[resi++]=matrix[i][j];           
            }

            int k;
            for(k=i+1; k<m-i-1 && resi!=m*n; k++)       //traversing right column top to bottom
            {
                res[resi++]=matrix[k][j-1];         
            }

            int l;
            for(l=j-1; l>=i && resi!=m*n; l--)          //traversing lower row right to left 
            {
                res[resi++]=matrix[k][l];           
            }

            int m1;
            for(int m1=k-1; m1>i && resi!=m*n; m1--)    //traversing left column bottom to top
            {
                res[resi++]=matrix[m1][i];          
            }
        }
        return res;
    }
};
