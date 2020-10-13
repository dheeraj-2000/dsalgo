/*** Problem link: https://leetcode.com/problems/shopping-offers/ **/


class Solution {
public:
    map<vector<int> ,int>dp;
    vector<int>cost;
    vector<vector<int> >off;
    int n;
    int solve(vector<int>req)
    {
       
        if(dp.find(req)!=dp.end())
            return dp[req];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=req[i]*cost[i];
        }
        if(ans==0)
        {
            return dp[req]=0;
        }
        for(auto j:off)
        {
            vector<int>nereq=req;
            int f=0;
            for(int i=0;i<n;i++)
             {     
            nereq[i]-=j[i];
            if(nereq[i]<0)
            {
                f=1;
                break;
            }
                
            }
            if(f)
                continue;
            ans=min(ans,j[n]+solve(nereq));
        }
        dp[req]=ans;
        return ans;
    }
    int shoppingOffers(vector<int>& a, vector<vector<int>>& b, vector<int>& req) {
         n=a.size();
      swap(off,b);
        swap(cost,a);
       return solve(req);
    }
};
