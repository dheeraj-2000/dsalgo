#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> solve(vector<int> &B) {
      // int x = B.size();
      sort(B.begin(), B.end());
      for(int i=0; i<B.size()-1; i=i+2){
            swap(B[i], B[i+1]);
      }
      return B;

}

int main(){
      int n, input;
      cin>>n;
      vector<int> v(n);
      for(auto i=0; i<n; i++){
            cin>>input;
            v.push_back(input);
      }
      solve(v);
      for(int i=0; i<v.size(); i++)
            cout<<v[i];

}
