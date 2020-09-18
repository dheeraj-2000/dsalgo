#include<bits/stdc++.h>
#include<vector>
using namespace std;
// // Using Brute force Time: (n^2)  Space: (1)
// int solve(vector<int> &A) {
//
//       for (int i=0; i<A.size(); i++){
//             for(int j=i+1;j<A.size();j++){
//                   if(A[j]==A[i])
//                   return A[j];
//                   break;
//             }
//
//       }
//
//       return -1;
// }

// // Using O(n) complexity and O(n) space;
// int solve(vector<int> &a) {
//       vector<int> A = a;
//       for (int i=0; i<A.size(); i++){
//             int temp = abs(A[i])-1;
//             if(A[temp] < 0){
//                   // int x = -A.at(temp);
//                   return a[i];
//                   break;
//             }
//             A[temp] = -A[temp];
//       }
//
//       return -1;
// }


// Hash map T: O(n), Space: O(n)
int solve(vector<int> &A) {
      unordered_map<int,int>counts;
      for(int i=0;i<A.size();i++)
            counts[A[i]]++;
      for(auto it:counts){
        if(it.second>1)
            return it.first;
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
