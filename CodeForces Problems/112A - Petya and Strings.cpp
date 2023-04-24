//Author: Akash Gautam (@geekblower)
//Date: 25-06-2022
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define endl '\n'
#define GEEKBLOWER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define TEST_CASES create(t);while(t--)
#define SOLVE solve(); return 0;
#define VI vector<int>
#define PB push_back
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(a.begin(),a.end())
#define loop(i,a,b,c) for(int i=a;i<b;i+=c)
#define revloop(i,a,b,c) for(int i=a;i<b;i-=c)
#define start_loop loop(i,0,n,1)
#define start_revloop revloop(i,0,n,1)
#define create(n) int n;cin>>n;
#define def(a,n) int a[n];start_loop cin>>a[i];
#define print(a) for(auto i : a){cout<<i<<" ";}cout<<endl;
const int MOD = 1e9+7;

int solve() {
    string str1, str2;
    cin>>str1>>str2;
    int n = str1.length();
    start_loop {
        char ch1 = toupper(str1[i]);
        char ch2 = toupper(str2[i]);
        if(ch1 > ch2)
            return 1;
        if(ch1 < ch2)
            return -1;
    }
    return 0;
}

int32_t main() {
    GEEKBLOWER
    int n = solve();
    cout<<n;
}
