#include<bits/stdc++.h>
#include<vector>
using namespace std;

// // Using O(n) complexity and O(n) space;
int solve(vector<int> &A) {

      for (int i=0; i<A.size(); i++){
            int temp = abs(A[i])-1;
            if(A[temp] < 0){
                  // int x = -A.at(temp);
                  return -A[i];
                  break;
            }
            A[temp] = -A[temp];
      }

      return -1;
}


int main(){
      int n;
      int input;
      cin>>n;
      vector<int> v;
      for(auto i=0; i<n; i++){
            cin>>input;
            v.push_back(input);
      }
      cout<<solve(v);

}
