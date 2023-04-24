//Author: Akash Gautam (@geekblower)
//Date: 25-06-2022
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define GEEKBLOWER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define TEST_CASES create(t);while(t--)
#define SOLVE solve(); return 0;
#define VI vector<int>
#define PB push_back
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define loop(i,a,b,c) for(int i=a;i<b;i+=c)
#define revloop(i,a,b,c) for(int i=a;i<b;i-=c)
#define start_loop loop(i,0,n,1)
#define start_revloop revloop(i,0,n,1)
#define create(n) int n;cin>>n;
#define def(a,n) int a[n];start_loop cin>>a[i];
#define print(a) for(auto i : a){cout<<i<<" ";}cout<<endl;
const int MOD = 1e9+7;

void solve() {
    bool flag = true;
    create(n)
    create(x)
    def(arr, n)
    
    loop(i, 0, n-1, 1) {
        if(arr[i] > arr[i+1]) {
            if((arr[i]+arr[i+1]) > x) {
                flag = false;
                break;
            } else {
                swap(arr[i], arr[i+1]);
            }
        }
    }
    
    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

int32_t main() {
    GEEKBLOWER
    TEST_CASES
    SOLVE
}