#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
      int find_gcd(int n, int m){
            if (m == 0)
                  return n;
            return find_gcd(m, n%m);

      }
};



int main(){
      int a, b;
      cin>>a>>b;
      Solution obj;
      cout<<obj.find_gcd(a, b);
}
