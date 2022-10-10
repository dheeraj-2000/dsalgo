//Problem Link: https://practice.geeksforgeeks.org/problems/distinct-palindromic-substrings/0/

#include <bits/stdc++.h>
using namespace std;

void solve(string s){
    int n = s.size();
    
    bool dp[n+1][n+1];
    memset(dp,false,sizeof(dp));
    
    set<string> st;
    
    //diagonal elements (single character is palindrome)
    for(int i=0;i<n;i++){
        dp[i][i] = true;
        st.insert(s.substr(i,1));
    }
    
    //2 length characters 
    for(int i=0;i<n-1;i++){
        if(s[i] == s[i+1]){
            dp[i][i+1] = true;
            st.insert(s.substr(i,2));
        }
    }
    
    //more than 2 length characters
    for(int k=2;k<n;k++){
        int i=0,j=k;
        
        while(j<n){
            
            if(s[i] == s[j] && dp[i+1][j-1]){
                dp[i][j] = true;
                st.insert(s.substr(i,j-i+1));
            }else{
                dp[i][j] = false;
            }
            
            i++; j++;
        }
    }
    
    cout << st.size() << endl;
}

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    string s;
	    cin >> s;
	    solve(s);
	}
	return 0;
}
