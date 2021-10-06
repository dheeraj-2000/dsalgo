//The time complexity of the solution is O(n*m) where n is the length of the longer string and m is the length of shorter string
//The space complexity of the solution is O(n) where n is the length of the shorter string

#include <iostream>
#include <vector>

using namespace std;

int shortestCommonSupersequence(string X, string Y)
{
    int m=X.length(), n=Y.length();

    if(m<n)
        return shortestCommonSupersequence(Y,X); //to ensure that Y is the shorter string

    vector<vector<int>> dp(2, vector<int>(n+1));
    
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0)
                dp[i%2][j]=j;
            else if(j==0)
                dp[i%2][j]=i;
            else
            {
                if(X[i-1]==Y[j-1])
                {
                    dp[i%2][j]=dp[(i+1)%2][j-1]+1;
                }
                else
                {
                    dp[i%2][j]=min(dp[(i+1)%2][j],dp[i%2][j-1])+1;
                }
            }
        }
    }
    return dp[m%2][n];
}

int main()
{
    string X,Y;
    cin>>X>>Y;
    cout<<shortestCommonSupersequence(X,Y)<<"\n";
    return 0;
}
