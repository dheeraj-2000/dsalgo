#include<bits/stdc++.h>
using namespace std;

void binary(int n){
      for(int i=13; i>-1; i--)
      cout<<((n>>i)&1);
      cout << endl;
}

int main(){
      int t;
      cin>>t;
      while(t--){
            int n;
            cin>>n;
            binary(n);
      }
}
