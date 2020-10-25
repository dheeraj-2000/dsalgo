#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

int solve(vector<int> &A){
      // vector b = A;
      // int x= ;
      // cout<<x<<endl;
      if(A.size()-1<2) {
            return 0;
      }
      priority_queue<int, vector<int>, greater<int>> my_pq;
      for(auto i: A){
            my_pq.push(i);
      }

      // size_of_arr = A.size();
      int max_gap = INT_MIN;

      int temp1 = my_pq.top();
      my_pq.pop();
      while(!my_pq.empty()){
            int temp2 = my_pq.top();
            my_pq.pop();
            max_gap = max(max_gap, temp2-temp1);
            temp1 = temp2;
      }
      return max_gap;

}

int main(){
      int n, input;
      cin>>n;
      vector<int> v(n);
      for(auto i=0; i<n; i++){
            cin>>input;
            v.push_back(input);
      }
      cout<<solve(v);

}
