#include<bits/stdc++.h>
#include<vector>
using namespace std;

int solve(vector< vector <int>> &B, int n, int m) {
      // int x = B.size();
      // sort(B.begin(), B.end());
      cout<<B.size();
      cout<<B[0].size();
      for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                  cout<<B[i][j];
            cout<<endl;
      }
      // return B;

}

int main(){
      int n, m, input;
      cin>>n;
      cin>>m;
      vector< vector <int>> v(n, vector<int> (m));
      for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                  cin>>input;
                  v[i].push_back(input);
            }
      }
      solve(v, n, m);
      // for(int i=0; i<v.size(); i++)
      //       cout<<v[i];
}
