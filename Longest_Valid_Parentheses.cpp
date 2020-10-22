//32. Longest Valid Parentheses
//https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n=s.size(),matchidx,maxlen=0;
        vector<int>dp(n,0);
        
        for(int i=1;i<n;i++){
            
            if(s[i]==')'){
                
                    matchidx=i-dp[i-1]-1;
                
                if(matchidx>=0 && s[matchidx]=='('){
//                     ()()()--->2+dp[index-1]
                    dp[i]+=2+dp[i-1];
                    
//                     adding before matches
                    if(matchidx-1>=0)
                        dp[i]+=dp[matchidx-1];
                  
                }
            }
            
//              length of the longest 
            maxlen=max(maxlen,dp[i]);
        }
        
        return maxlen;
    }
};
