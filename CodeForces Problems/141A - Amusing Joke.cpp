//Author: Akash Gautam (@geekblower)
//Date: 29-06-2022
#include <iostream>
#include <string>
#include <algorithm>
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
#define SORT(a) sort(ALL(a));
#define loop(i,a,b,c) for(int i=a;i<b;i+=c)
#define revloop(i,a,b,c) for(int i=a;i>=b;i-=c)
#define start_loop loop(i,0,n,1)
#define start_revloop revloop(i,n,0,1)
#define create(n) int n;cin>>n;
#define def(a,n) int a[n];start_loop cin>>a[i];
#define print(a) for(auto i : a){cout<<i<<" ";}cout<<endl;
const int MOD = 1e9+7;

void solve() {
    string str1, str2, str3, mystr;
    cin>>str1>>str2>>str3;
    mystr = str1 + str2;
    
    SORT(mystr)
    SORT(str3)
    
    if(str3==mystr)
        display("YES")
    else
        display("NO")
}

int32_t main() {
    GEEKBLOWER
    SOLUTION
}
