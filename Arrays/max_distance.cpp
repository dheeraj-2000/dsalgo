#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>

using namespace std;

int solve(vector<int> &b){
      int n = b.size();
      vector<pair<int, int>> A;

      int i;
      for(i=0; i<n; i++){
            A.push_back(make_pair(b[i], i));
      }

      // for(i=0; i<n; i++){
      //       cout<<b[i]<<'\t';
      // }
      sort(A.begin(), A.end());
      int min_ = INT_MAX;
      int max_ = -1;
      // cout<<n<<endl;
      for(i=0; i<n; i++){
            min_ = min(A[i].second, min_);
            max_ = max(max_, A[i].second - min_);
            // cout<<"min "<<min_<<'\t' << "max "<<max_<<endl;
            // cout<<A[i].first<<'\t'<<A[i].second<<endl;
      }

      return n;

}

int main(){
      int n, input;
      cin>>n;
      vector<int> v;
      for(auto i=0; i<n; i++){
            cin>>input;
            v.push_back(input);
      }
      cout<<solve(v);

}
