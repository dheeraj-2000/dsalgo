#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int n = digits.size();
      int i = n-1;
      if(digits[i] != 9){
            digits[i]++;
      }
      else{
            while(digits[i] == 9 && i > 0){
                  digits[i] = 0;
                  i--;
            }
            if(i == 0 && digits[i] == 9){
                  digits[i] = 0;
                  auto it = digits.insert(digits.begin(),1,1);
            }
            else{
                  digits[i]++;
            }
      }
      return digits;
      }
};

int main(){
      int t;
      cin>>t;
      // vector <int> v;
      vector<int> v;
      for(int i =0; i<t; i++){
            int input;
            cin>>input;
            v.push_back(input);
      }
      Solution s;
      s.plusOne(v);
      for(int i=0; i<v.size(); i++)
            cout<<v[i];
      // cout<<s.plus_one(v)<<endl;
}



// class Solution {
// public:
//       vector plusOne(vector& digits) {
//       int n = digits.size();
//       int i = n-1;
//       if(digits[i] != 9){
//             digits[i]++;
//       }
//       else{
//             while(digits[i] == 9 && i > 0){
//                   digits[i] = 0;
//                   i--;
//             }
//             if(i == 0 && digits[i] == 9){
//                   digits[i] = 0;
//                   auto it = digits.insert(digits.begin(),1,1);
//             }
//             else if(i == 0 && digits[i] != 9){
//                   digits[i]++;
//             }
//             else{
//                   digits[i]++;
//             }
//       }
//       return digits;
//       }
// };
