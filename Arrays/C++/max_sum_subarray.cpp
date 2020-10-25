// @dheeraj
// Max sum of subarra using Kaden's Algorithms

#include<iostream>
#include<vector>

using namespace std;

long int max_sum_subarr(vector<long int>& arr) {
      long int max_curr=arr[0];
      long int max_global=arr[0];

      for(int i=1; i<arr.size(); i++){
            max_curr= max(arr[i], max_curr+arr[i]);
            if(max_curr > max_global) max_global=max_curr;
      }
      return max_global;
}

int main(){
      int n, input;
      cin>>n;
      vector<long int> v;
      for(auto i=0; i<n; i++){
            cin>>input;
            v.push_back(input);
      }
      cout<<max_sum_subarr(v);

}
