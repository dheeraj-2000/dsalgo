// Ugly numbers are those numbers which are disvible by 2,3,5 (by default with 1).
// @dheeraj

#include<iostream>
using namespace std;

int get_min(int x, int y, int z){           //to find minimum of three number (you cna also use built-in function for min)
      int min;
      min=x<y?(x<z?x:z):(y<z?y:z);
      return min;
}

int get_nth_ugly_number(int n){           //function to find nth ugly number
      int iterattor_factor_2=0,  iterattor_factor_3=0, iterattor_factor_5=0;
      int ugly[n];                         //arrar to store ugly numbers
      ugly[0]=1;                           //defining initial uglgy number which is 1
      long long int track_next_ugly = 1;    //to track next coming ugly number, hence defining st to be 1
      long long int next_multiple_of2 = 2;
      long long int next_multiple_of3 = 3;
      long long int next_multiple_of5 = 5;

      for(int i=1; i<n; i++){
            track_next_ugly = get_min(next_multiple_of2, next_multiple_of3, next_multiple_of5);     //finding next ugly number
            ugly[i]= track_next_ugly;
            if(track_next_ugly==next_multiple_of2){
                  iterattor_factor_2++;                                              //increase iterator of ugly numbers whose factor is 2
                  next_multiple_of2 = ugly[iterattor_factor_2]*2;
            }
            if(track_next_ugly==next_multiple_of3){
                  iterattor_factor_3++;                                              //increase iterator of ugly numbers whose factor is 3
                  next_multiple_of3 = ugly[iterattor_factor_3]*3;
            }
            if(track_next_ugly==next_multiple_of5){
                  iterattor_factor_5++;                                             //increase iterator of ugly numbers whose factor is 5
                  next_multiple_of5 = ugly[iterattor_factor_5]*5;
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
