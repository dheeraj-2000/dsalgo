#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minInsAndDel(int a[], int b[], int n, int m) {
        // code here
        vector<int>x,l,mp(1e5+1,0);
        int i;
        for(i=0;i<m;i++)
        {
            mp[b[i]]++;
        }
            for(i=0;i<n;i++)
        {
            if(mp[a[i]])
            x.push_back(a[i]);
        }
        for(auto k: x)
        {
            auto it=lower_bound(l.begin(),l.end(),k);
            if(it!=l.end())
            *it=k;
            else
            l.push_back(k);
        }
        return n+m-2*l.size();
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends
