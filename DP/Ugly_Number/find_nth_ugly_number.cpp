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

int get_nth_ugly_number(int n){
      int i_2=0,  i_3=0, i_5=0;
      int ugly[n];
      ugly[0]=1;
      long long int track_next_ugly = 1;
      long long int next_multiple_of2 = 2;
      long long int next_multiple_of3 = 3;
      long long int next_multiple_of5 = 5;

      for(int i=1; i<n; i++){
            track_next_ugly = get_min(next_multiple_of2, next_multiple_of3, next_multiple_of5);
            ugly[i]= track_next_ugly;
            if(track_next_ugly==next_multiple_of2){
                  i_2++;
                  next_multiple_of2 = ugly[i]*2;
            }
            if(track_next_ugly==next_multiple_of3){
                  i_3++;
                  next_multiple_of3 = ugly[i]*3;
            }
            if(track_next_ugly==next_multiple_of5){
                  i_5++;
                  next_multiple_of5 = ugly[i]*5;
            }
      }
      return track_next_ugly;
}



// Driver function
int main(){
      int n;
      cout<< "Which nth ugly number you wanna find??: ";
      cin >> n;
      cout<< n <<"th ugly number is: "<<get_nth_ugly_number(n);
}
