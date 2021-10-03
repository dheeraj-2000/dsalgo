#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define mod 1000000007
#define MAX 1e9
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=(ll)a;i<(ll)b;i++)
#define revrep(i,a,b) for(i=(ll)a;i>=(ll)b;i--)
#define ii pair<ll,ll>
#define MP make_pair
#define pb push_back
#define f first
#define se second
#define ll long long int
#define vi vector<ll>
ll modexp(ll a,ll b){ ll res = 1; while(b > 0){  if(b & 1) res = (res * a)%mod;  a = (a * a)%mod;  b/=2;  }  return res; }
#define rs resize
typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > OST;
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif

const ll N = 1e5 + 2;
ll t,l,r,n;
string s;
ll dp[65][2][2][3][3];
void convert(ll a)
{
    s = "";
    if(a == 0) s = "0";
    while(a > 0){
        s += char('0' + a % 2);
        a /= 2;
    }
    n = s.length();
    reverse(all(s));
}
ll solve(ll i,bool small,bool all,ll a,ll b)
{
    ll &res = dp[i][small][all][a][b];
    if(res != -1) return res;

    if(i == n) return res = (all ? 1 : 0);

    res = 0;
    ll limit = (small ? 1 : s[i] - '0');
    for(ll use = 0;use <= limit;++use){
        bool nwall = all;
        if(a == 1 && b == 0 && use == 1) nwall = 1;
        res += solve(i + 1,(use < s[i] - '0' ? 1 : small),nwall,b,use);
    }
    return res;
}
int main()
{
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>l>>r;

        convert(r);
        memset(dp,-1,sizeof(dp));
        r = solve(0,0,0,2,2);

        convert(l - 1);
        memset(dp,-1,sizeof(dp));
        l = solve(0,0,0,2,2);

        cout<<r - l<<endl;
    }
    return 0;
}
