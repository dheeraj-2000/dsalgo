#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    bool isSafe(int n, int r, int c, vector<vector<int>> &m, vector<vector<int>>& visited) {
        if(r>=0 and c>=0 and r<n and c<n and m[r][c] == 1 and visited[r][c] == 0) return true;
        
        return false;
    }
    
    void sol(int n, int r, int c, string op, vector<vector<int>> &m, vector<string>& ans, vector<vector<int>>& visited) {
        if(r == n-1 and c == n-1 and m[r][c] == 1) {
            ans.push_back(op);
            return;
        }
        
        if(isSafe(n,r,c,m,visited)) {
            visited[r][c] = 1;
            
            sol(n,r-1,c,op+'U',m,ans,visited);

            sol(n,r+1,c,op+'D',m,ans,visited);

            sol(n,r,c-1,op+'L',m,ans,visited);

            sol(n,r,c+1,op+'R',m,ans,visited);

            
            visited[r][c] = 0;

        }
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        
        vector<vector<int>> visited(n,vector<int>(n));
        
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) visited[i][j] = 0;
        
        sol(n,0,0,"",m,ans,visited);
        
        sort(ans.begin(),ans.end());
        
        if(ans.size()>0) return ans;
        else return {"-1"};
    }
};
