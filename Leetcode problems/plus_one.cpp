#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

          // int x=0;
          // int temp = digits[0];
          // while(temp==0){
          //       // int x=0;
          //       temp = digits[x+1];
          //       x++;
          //       // count++;
          //   }
            // for(int i=x; i<digits.size(); i++)

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
            int x=0;
            int temp = digits[0];
            while(temp==0){
                  // int x=0;
                  temp = digits[x+1];
                  x++;
                  // count++;
              }
             vector<int>::iterator it1, it2;
            it1 = digits.begin(), it2=digits.begin() + x;
            digits.erase(it1, it2);
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

      // int x=0;
      // int temp = v[0];
      // while(temp==0){
      //      // int x=0;
      //      temp = v[x+1];
      //      x++;
      //      // count++;
      //   }
      for(int i=0; i<v.size(); i++)
            cout<<v[i];
      // cout<<s.plus_one(v)<<endl;
}
