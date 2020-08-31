#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
      int return_val(char roman){
            if (roman == 'I') return 1;
            if (roman == 'V') return 5;
            if (roman == 'X') return 10;
            if (roman == 'L') return 50;
            if (roman == 'C') return 100;
            if (roman == 'D') return 500;
            if (roman == 'M') return 1000;
      }

public:
      int roman_to_integer(string s){
            int result = 0;
            for (int i=0; i<s.size(); i++){
                  int num1 = return_val(s[i]);
                  if(i+1 < s.size()){
                        int num2 = return_val(s[i+1]);
                        if(num1 >= num2)
                              result = result + num1;
                        else{
                              result = result + num2 - num1;
                              i++;
                        }
                  }
                  else
                        result = result + num1;
            }
            return result;
      }
};

int main(){
      string str;
      cin >> str;
      Solution object;
      cout<< object.roman_to_integer(str);
}
