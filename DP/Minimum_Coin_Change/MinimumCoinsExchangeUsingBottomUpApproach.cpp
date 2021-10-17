#include <iostream>
#include <climits>

using namespace std;

int minCoinsExchange(int coins[],int T,int N)
{
    int dp[10000]={0};

    //we need to iterate over all the states 1 to N

    for(int n=1;n<=N;n++)
    {
        dp[n]=INT_MAX;

        for(int i=0;i<T;i++)
        {
            if(n-coins[i]>=0)
            {
                int subProb=dp[n-coins[i]];
                dp[n]=min(dp[n],subProb+1);
            }
        }
    }

    return dp[N];
}

int main()
{   
    int t;
    cin>>t;

    while(t--)
    {
        int n,T;
        cin>>n>>T;

        int coins[T];

        for(int i=0;i<T;i++)
        {
            cin>>coins[i];
        }

        cout<<minCoinsExchange(coins,T,n)<<endl;
    }



    return 0;
}