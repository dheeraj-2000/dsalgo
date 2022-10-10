//Author: Akash Gautam (@geekblower)
//Date: 14-08-2022
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define GEEKBLOWER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define TEST_CASES create(t);while(t--)
#define SOLUTION solve(); return 0;
#define display(n) cout<<n<<endl;
#define VI vector<int>
#define PB push_back
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define loop(i,a,b,c) for(int i=a;i<b;i+=c)
#define revloop(i,a,b,c) for(int i=a;i>=b;i-=c)
#define start_loop loop(i,0,n,1)
#define start_revloop revloop(i,n,0,1)
#define create(n) int n;cin>>n;
#define def(a,n) int a[n];start_loop cin>>a[i];
#define print(a) for(auto i : a){cout<<i<<" ";}cout<<endl;
#define vector(a,n) VI a;loop(i,0,n,1){int x;cin>>x;a.PB(x);}
inline int GCD(int a,int b){return !b?a:GCD(b,a%b);}
const int MOD = 1000000007;

priority_queue<pair<int,int>> p,nul;
map<int,vector<int>> k;

void otto() {
    while(!p.empty()) {
        cout<<-p.top().first<<' ';
        p.pop();
    }
    cout << endl;
}

void solve() {
    p = nul;
    k.clear();
    
    create(n)
    create(x)
    create(y)
    
    loop(i, 1, n+1, 1) {
        create(t)
        p.push({-t,i});
    }
    
    loop(i, 1, y+1, 1) {
        pair<int,int> _= {-((-p.top().first) ^ x), p.top().second};
        k[p.top().second].push_back (i);
        
        if(k[p.top().second].size() == 4) {
            int s = k[p.top().second][3] - k[p.top().second][1];
            i += (y-i) / s*s;
            
            for(; i<=y; i++) {
                pair<int,int> t = {-((-p.top().first) ^ x), p.top().second};
                p.pop();
                p.push (t);
            }
            
            otto();
            return;
        }
        
        p.pop();
        p.push (_);
    }
    
    otto();
}

int32_t main() {
    GEEKBLOWER
    TEST_CASES
    SOLUTION
}