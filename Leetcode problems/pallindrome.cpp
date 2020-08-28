#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
      bool check_pallindrome(int num){
            int reverse_num = 0;
            int temp = num, flag = 0;
            if (num <0 )
                  return false;
            else{
                  while(temp !=0){
                        reverse_num = reverse_num*10 + temp%10;
                        temp = temp/10;
                  }
            }
            return reverse_num == num;
      }
};

int main(){
      int num = 746384741;
      Solution object;
      cout<<object.check_pallindrome(num);
}
