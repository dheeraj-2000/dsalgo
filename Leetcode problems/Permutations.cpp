class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    int n;
    
    void dfs(vector<int>& path, vector<int>& vis){
        if(path.size()==n){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                path.push_back(v[i]);
                vis[i]=1;
                dfs(path, vis);
                vis[i]=0;
                path.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        v=nums;
        n=nums.size();
        vector<int> vis(n,0);
        vector<int> path;
        dfs(path, vis);
        return ans;
    }
};