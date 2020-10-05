#include<bits/stdc++.h>
using namespace std;


int main(){
      int n;
      cin>>n;
      // Solution obj;
      // cout << obj.decimal_to_binary(n);
      vector<int> v;
      while(n>0){
            int temp = n%2;
            v.push_back(temp);
            n = n/2;
      }
      for(auto i: v)
            cout<<i;


}
