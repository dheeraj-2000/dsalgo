#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findnextterm(string dude){
        string result="";
        int count=1;
        for(int i=1;i<dude.size();i++){
            if(dude[i]==dude[i-1]){
                count++;
            }
            else{
                result += to_string(count);
                result.push_back(dude[i-1]);
                count = 1;
            }
        }
        result += to_string(count);
        result.push_back(dude.back());
        return result;
    }
    string countAndSay(int n) {
        string result="1";
        for(int i=1;i<n;i++){
            result = findnextterm(result);
        }
        return result;
    }
};

int main(){
      // int n;
      // cin>>n;
      // vector<int> v;
      // for(int i =0; i<n; i++){
      //       int input;
      //       cin>>input;
      //       v.push_back(input);
      // }
      // cout << v.size()<<endl;

      vector<int> myvector{1,2,3,4,5,6,7,8,9};
      // for (int i=1;i<=9;i++){
      //     setofNum[i-1] = i;
      // }
      // generate (myvector.begin(), myvector.end(), UniqueNumber);

      for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
            cout<<*it<<endl;

}
