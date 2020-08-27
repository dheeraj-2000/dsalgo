#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
      int reverse_num(int t){
            int result = 0;
            while(t !=0){
                  if (INT_MAX > t) return 0;
                  if (INT_MIN < t) return 0;

                  result = result*10 + (result%10);
                  t = t/10;
            }
            return t;
      }
};

int main(){
      int num = 123;
      Solution ob;
      cout<<ob.reverse_num(num);
}
