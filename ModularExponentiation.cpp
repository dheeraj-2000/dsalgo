/*Ajay*/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int modular_expo(int a,int b){
  a=a%mod;
  int res=1;
  while(b>0){
    if(b&1){
      res=res*a % mod;b--;
    }
    else{
      a=a*a % mod;b/=2;
    }
  }
  return res;
}
int main(){
  int a,b;
  cin>>a>>b;
  cout<<modular_expo(a,b);
  return 0;
}
