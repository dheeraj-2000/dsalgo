#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
#define f(i,mx_value,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define mod 1000000007

int main()
{
    // take input
    int n,cap;
    cin>>n>>cap;
    ll val[n],wt[n];
    for(int i=0;i<n;i++){
        cin>>wt[i]>>val[i];
    }
    ll mx_value=n*1000;

    // dp[position][collected_value] stores min_weight required for this value
    ll dp[n][mx_value+1];

    // initialising dp
    for(int i=0;i<n;i++){
        // value=0 => no weight required
        dp[i][0]=0;
    }
    for(int i=1;i<=mx_value;i++){
        if(val[0]==i){
            dp[0][i]=wt[0];
        }else{
            dp[0][i]=INT_MAX;
        }
    }

    for(int i=1;i<n;i++){ //position
        for(int j=1;j<=mx_value;j++){ //values
            ll temp=dp[i-1][j];
            if(j-val[i]>=0 && dp[i-1][j-val[i]]!=INT_MAX){
                temp=min(temp,wt[i]+dp[i-1][j-val[i]]);
            }
            dp[i][j]=temp;
        }
    }

    ll ans=0;
    for(int i=1;i<=mx_value;i++){
        if(dp[n-1][i]<=cap){
            ans=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
