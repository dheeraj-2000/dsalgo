/*
Leetcode: 200
Link: https://leetcode.com/problems/number-of-islands/

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <climits>
#include <functional>

using namespace std;

void get_connect_islands(vector<vector<char>>& grid, int i, int j, vector<vector<int>> &directions){
    grid[i][j] = '0';
    int m = grid.size(), n = grid[0].size(), comp = 0;
    for(int d=0; d<directions.size(); d++)
    {
        int x = i + directions[d][0];
        int y = j + directions[d][1];
        if(x>=0 && x<m && y>=0 && y<n && grid[x][y] == '1')
            get_connect_islands(grid, x, y, directions);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size(), no_of_islands = 0;
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(grid[i][j] =='1')
            {
                no_of_islands++;
                get_connect_islands(grid, i, j, directions);                        
            }
        }
    }
   
    return no_of_islands;
}

int main()
{
    vector<vector<char>> grid{{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    int number_of_islands = numIslands(grid);
    cout<<"The number of islands in the given grid is "<<number_of_islands<<".";
    return 0;
}