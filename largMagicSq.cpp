/*
A k x k magic square is a k x k grid filled with integers such that every row sum, every column sum, and both diagonal sums are all equal. The integers in the magic square do not have to be distinct. Every 1 x 1 grid is trivially a magic square.

Given an m x n integer grid, return the size (i.e., the side length k) of the largest magic square that can be found within this grid.

 

Example 1:


Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
Output: 3
Explanation: The largest magic square has a size of 3.
Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
- Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
- Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
- Diagonal sums: 5+4+3 = 6+4+2 = 12
Example 2:


Input: grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
Output: 2
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j] <= 106

*/

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size();
        
        int pre_row[r][c];  // prefix sum row wise
        int pre_col[r][c];  // prefix sum column wise
        
        // pre_row calculation
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(j==0)
                    pre_row[i][j] = grid[i][j];
                else
                    pre_row[i][j] = pre_row[i][j-1] + grid[i][j];
            }
        }
        
        // pre_col calculation
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(i==0)
                    pre_col[i][j] = grid[i][j];
                else
                    pre_col[i][j] = pre_col[i-1][j] + grid[i][j];
            }
        }
        
        int l=min(r,c);
        // check for all l in decreasing order
        while(l)
        {
            //check for a magic square of size l
            for(int i=0; i+l-1<r; i++)
            {
                for(int j=0; j+l-1<c; j++)
                {
                    //check for magic square of size l starting at (i,j)
                    
                    //check row wise, col wise, diagonal wise and anti-diagonal wise condition
                    bool row = true, col = true;
                    int r_sum = pre_row[i][j+l-1] - pre_row[i][j] + grid[i][j];
                    int c_sum = pre_col[i+l-1][j] - pre_col[i][j] + grid[i][j];
                    int dia_sum = grid[i][j], anti_dia_sum = grid[i][j+l-1];
                    
                    if(r_sum!=c_sum) continue;
                    
                    int step=1;
                    while(step<l)
                    {
                        int tmp_r_sum = pre_row[i+step][j+l-1] - pre_row[i+step][j] + grid[i+step][j];
                        int tmp_c_sum = pre_col[i+l-1][j+step] - pre_col[i][j+step] + grid[i][j+step];
                        
                        if(tmp_r_sum != r_sum)
                        {
                            row = false;
                            break;
                        }
                        if(tmp_c_sum != c_sum)
                        {
                            col = false;
                            break;
                        }
                        
                        dia_sum += grid[i+step][j+step];
                        anti_dia_sum += grid[i+step][(j+l-1)-step];
                        step++;
                    }
                    
                    if(row==true && col==true && dia_sum==anti_dia_sum && dia_sum==r_sum) return l;
                }
            }
            l--;
        }
        return 1;
    }
};