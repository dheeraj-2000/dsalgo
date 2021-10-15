/* Author: Ajeet Kumar Jaiswal */
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

void init_code(){ 
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   #ifndef ONLINE_JUDGE 
   freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);freopen("error.txt","w",stderr);
   #endif 
}

void readvec(vector<int> &arr){for(auto &it:arr){cin>>it;}}


void solve(){
   int n;
   cin>>n;
   vector<int>arr(n);
   readvec(arr);
   sort(arr.begin(),arr.end());// As sorting will give us perfect swaping such all smaller one are at front and greater one at back
   int sum=0;
   int count=0;
   for(int i=0;i<n;i++){
      if(sum>arr[i]){
         count++;
      }
      else{
         sum+=arr[i];// this done keeping in the mind this test case: 1 2 3 4 6 so this we have already sorted it but here our sequence will not be like that here it will be like 1 2 3 6 4 as we know we have to neglect 4 to consider 6. so that's why we will not add 4 in 1+2+3 instead we'll directly jump at 6 so that the one we can considered can be maximized
      }
   }
   cout<<n-count;
   return ; 
}


 
int32_t main(){  
   init_code();
   int t=1; //cin >> t;
   while(t--){
      solve();
      cout<<"\n";
   }
   return 0;
}

