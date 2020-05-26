// Ugly numbers are those numbers which are disvible by 2,3,5 (by default with 1).
// @dheeraj

#include<iostream>
using namespace std;

int get_min(int x, int y, int z){           //to find minimum of three number (you cna also use built-in function for min)
      if(x < y) {
         if(x < z)
            return x;
         else
            return z;
      }else {
         if(y < z)
            return y;
         else
            return z;
      }
   }





// Driver function
int main(){
      int n;
      cout<< "Which nth ugly number you wanna find??: ";
      cin >> n;
      cout<< n <<"th ugly number is: "<<get_nth_ugly_number(n);
}
