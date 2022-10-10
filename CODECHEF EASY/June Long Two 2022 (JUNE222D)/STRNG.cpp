//Author: Akash Gautam (@geekblower)
//Date: 26-06-2022
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
#define revloop(i,a,b,c) for(int i=a;i>b;i-=c)
#define start_loop loop(i,0,n,1)
#define start_revloop revloop(i,0,n,1)
#define create(n) int n;cin>>n;
#define def(a,n) int a[n];start_loop cin>>a[i];
#define print(a) for(auto i : a){cout<<i<<" ";}cout<<endl;
const int MOD = 1e9+7;

void createARR(int first[], int arr[], int last[], int n) {
    first[0] = arr[0];
    
    loop(i, 1, n, 1)
        first[i] = __gcd(first[i-1], arr[i]);
    
    last[n-1] = arr[n-1];
    
    revloop(i, n-2, -1, 1)
        last[i] = __gcd(last[i+1], arr[i]);
}

int OuterGCD(int l, int r, int first[], int last[], int n) {
    if (l==0)
        return last[r+1];
    
    if (r==n-1)
        return first[l-1];
    
    return __gcd(first[l-1], last[r+1]);
}

void solve() {
    create(n)

    int first[n] , last[n];
    def(arr,n)
    
    createARR(first , arr , last , n);
    
    int ans = 0 ;
    
    start_loop {
        if(OuterGCD(i, i, first, last, n) > 1)
            ans++;
    }
    
    display(ans)
}

int32_t main() {
    GEEKBLOWER
    TEST_CASES
    SOLUTION
}
