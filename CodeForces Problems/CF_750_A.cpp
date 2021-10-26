#include <bits/stdc++.h>
using namespace std;
#define int long long 
void solve(){
   int a,b,c;
   cin>>a>>b>>c;
   int sum=a+2*b+3*c;
   if(sum%2){
      cout<<"1";
   }
   else{
      cout<<"0";
   }
   return;
}
int32_t main(){  
   int t=1;cin>>t;
   while(t--){
      solve();
      cout<<"\n";
   }
   return 0;
}
