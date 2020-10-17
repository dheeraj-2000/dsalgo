#Word Break

bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        unordered_set<string> st;
        for(int i=0;i<wordDict.size();i++){
            st.insert(wordDict[i]);
        }
        for(int l=0;l<n;l++){
            for(int i=0,j=i+l;i<n && j<n;i++,j++){
                if(st.count(s.substr(i,j-i+1))){
                    dp[i][j] = true;
                }
                else{
                    for(int k=i;k<j;k++){
                        if(dp[i][k] && dp[k+1][j]){
                            dp[i][j] = true;
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }
