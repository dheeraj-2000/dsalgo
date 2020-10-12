/**** Link to the problem: https://leetcode.com/problems/cherry-pickup-ii/    *******/

class Solution {
public:
    
    int dp[71][71][71];
    int n,m;
    vector<vector<int> > vec;
    int solve(int x,int y,int z)
    {
        if(y<0||z<0||y>=m||z>=m)
            return -1e9;
        if(dp[x][y][z]!=-1)
            return dp[x][y][z];
        int ans=vec[x][y]+vec[x][z];
        if(y==z)
            ans/=2;
        if(x==n-1)
            return ans;
        int res=0;
        vector<int>dx={-1,0,1};
        
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                res=max(res,ans+solve(x+1,y+dx[i],z+dx[j]));
            }
        }
        dp[x][y][z]=res;
        return res;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vec=grid;
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m-1);
    }
};
