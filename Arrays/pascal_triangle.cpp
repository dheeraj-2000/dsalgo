#include<bits/stdc++.h>
#include<vector>
using namespace std;


vector<vector<int> > solve(int A) {
      vector< vector<int> > result;
      for( int i =0 ; i <A ; i++){
            result.push_back(vector<int>(i+1,1));
            for(int j=1; j<i; ++j) {
                  result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
      }
      return result;
}



int main(){
      int n, input;
      cin>>n;
      // vector<int> v(n);
      // for(auto i=0; i<n; i++){
      //       cin>>input;
      //       v.push_back(input);
      // }
      solve(n);
      // for(int i=0; i<v.size(); i++)
      //       cout<<v[i];

}
