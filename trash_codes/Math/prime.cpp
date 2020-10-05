#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
      bool find_prime(int n){
            if (n==1)
                  return 0;
            if (n==2)
                  return 1;
            int temp =2;
            while(temp <= n/2){
                  if (n% temp == 0){
                        return 0;
                        break;
                  }
                  temp++;
            }
            return 1;
      }
};




int main(){
      int a;
      cin>>a;
      Solution obj;
      cout<<obj.find_prime(a);
}
