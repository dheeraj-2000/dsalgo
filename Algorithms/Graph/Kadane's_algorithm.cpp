#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastIO          {ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define yes "Yes"
#define no "No"
#define pb push_back
#define mp make_pair
#define all(v) (v.begin(),v.end())
typedef vector<int> vi;
typedef vector<long long> vl;
vector<pair<ll,ll>> v;

int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

void solve()
{   
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
}


    
//<><><><><><><><><><><><>><><>><><><><><><><>

int32_t main()
{ 
    fastIO;
    auto start = std::chrono::high_resolution_clock::now(); 
    int t;
    t=1;
    cin>>t;
    while(t--)
    {
        solve();        
    } 
    
    return 0;
}