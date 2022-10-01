#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define _mp make_pair
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
#define _f first
#define _s second
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p._f); cerr << ","; _print(p._s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
#define _d(x) _p(x); cout << endl;
void _p(ll t)     {cout << t;}
void _p(int t)    {cout << t;}
void _p(string t) {cout << t;}
void _p(char t)   {cout << t;}
void _p(lld t)    {cout << t;}
void _p(double t) {cout << t;}
void _p(ull t)    {cout << t;}
template <class T, class V> void _p(pair <T, V> p);
template <class T> void _p(vector <T> v);
template <class T> void _p(set <T> v);
template <class T, class V> void _p(map <T, V> v);
template <class T> void _p(multiset <T> v);
template <class T, class V> void _p(pair <T, V> p) {cout << "{"; _p(p.ff); cout << ","; _p(p.ss); cout << "}";}
template <class T> void _p(vector <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
template <class T> void _p(set <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
template <class T> void _p(multiset <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
template <class T, class V> void _p(map <T, V> v) {cout << "[ "; for (auto i : v) {_p(i); cout << " ";} cout << "]";}
#define _sz(x) ((int)(x).size())
#define _a(x) (x).begin(), (x).end()

#define _pb push_back
#define _pob pop_back
#define int long long int
#define _vvi vector<vector<int>>
#define _vi vector<int>
#define _vvb vector<vector<bool>>
#define _mnh priority_queue<int, vector<int>, greater<int>>
#define _mxh priority_queue<int>
#define _m map<int, int>
#define _um unordered_map<int, int>
#define _vs vector<string>
#define _vvs vector<vector<string>>
#define _vc vector<char>
#define _vvc vector<vector<char>>
#define _vpi vector<pair<int, int>
#define _pi pair<int, int>
#define int long long int
/*-------------------------------------------------------------------------------------------------------------------------*/
class Solution {
  public:
  int ans = -1;
  void help(vector<int>v, int p, int k)
  {
      int n = v.size();
      if(n == 1)
      {
          ans = v[0]; 
          return;
      }
      p = ((p + k) % n);
      //debug(p); debug(n);
      v.erase(v.begin() + p);
        //debug(v);
        
      n--;
      
      // if(p >= n)
      // {
      //   p = p %
      // }
      //cout<<p<<" ";
      help(v, p, k);
  }
  
    int safePos(int n, int k) {
        vector<int>v;
        for(int i = 1; i <=n; i++ )
        {
            v.push_back(i);
        }
        // cout<<"v = [ ";
        // for(auto it : v)cout<<it<<" ";
        // cout<<" ]"<<endl;
        //debug(v);
        
        //int p = k % n;
        //debug(p);
        help(v, 0 , k - 1);
        return ans;
        
        
        
    }
};
void solve()
{
  int a, b;
  cin>>a>>b;
  Solution obj;
  
  cout<<obj.safePos(a, b)<<endl;
  
  


  return;
}
signed main() {
#ifndef ONLINE_JUDGE
  freopen("errors.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout); 
#endif
fastio();
// ll t;
// cin>>t;
// while(t--)
solve();
return 0;

}

