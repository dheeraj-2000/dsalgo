#include<bits/stdc++.h>
using namespace std;
int main(){
      int n;
      cin>>n;
      vector<int> v;
      for(int i =0; i<n; i++){
            int input;
            cin>>input;
            v.push_back(input);
      }
      cout << v.size()<<endl;

      for(auto i =v.begin(); i!=v.end(); i++){
            cout<<*i<<'\t';
      }
      cout<<'\n';
      for(auto i =v.cbegin(); i!=v.cend(); i++){
            cout<<*(i+1)<<'\t';
      }
      cout<<'\n';
      for(auto i =v.rbegin(); i!=v.rend(); i++){
            cout<<*i<<'\t';
      }
      cout<<'\n';
      for(auto i =v.crbegin(); i!=v.crend(); i++){
            cout<<*i<<'\t';
      }

}
