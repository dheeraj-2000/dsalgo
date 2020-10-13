/**** Problem link: https://leetcode.com/problems/wiggle-subsequence/ **********/

class Solution {
public:
    int wiggleMaxLength(vector<int>& a) {
        int n=a.size();
        if(n<=1)
            return n;
        vector<vector<int> >dp(n,vector<int>(2,0));
         dp[0][0]=1;
        dp[0][1]=1;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[i]-a[j]>0)
                {
                    dp[i][1]=max(dp[j][0]+1,dp[i][1]);
                }
                else if(a[i]-a[j]<0)
                {
                    dp[i][0]=max(dp[j][1]+1,dp[i][0]);
                }
            }
        }
     /*   for(int i=0;i<n;i++)
        {
            cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
        }*/
        int ans=1;
        for(int i=0;i<n;i++)
            ans=max(ans,max(dp[i][1],dp[i][0]));
        return ans;
    }
};
