class Solution {
public:
    int solve(int idx,int n,string s,vector<int> &dp)
    {
        if(idx==n)
        {
            return 1;
        }
        
        if(s[idx]=='0') return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        int flag=0;
        
        if(idx+1<n)
        {
            int d=(s[idx]-'0')*10;
            d+=(s[idx+1]-'0');
            if(d<=26) flag=1;
        }
        
        int take = 0;
        if(flag) 
        {
            take = solve(idx+2,n,s,dp);
        }
        
        int notTake = 0;
        notTake = solve(idx+1,n,s,dp);
        
        return dp[idx] = take + notTake;
    }
    
    int numDecodings(string s) {
        
        vector<int> dp(s.length()+1,-1);
        return solve(0,s.length(),s,dp);
        
    }
};
