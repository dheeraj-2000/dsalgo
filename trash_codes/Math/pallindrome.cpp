#include<bits/stdc++.h>
using namespace std;


int main(){
      int m, new_num=0;
      cin>>m;
      int n = m;
      // vector<int> v;
      while(n!=0){

            // int temp = n %10;
            new_num = 10*new_num + n%10;
            n = n/10;

      }
      // cout << n<<endl;
      // cout << new_num<<endl;
      if (new_num == m)
            cout << "isPallindrome";
      else
            cout<<"not Pallindrome";
}
