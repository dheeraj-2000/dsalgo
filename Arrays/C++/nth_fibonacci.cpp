#include<iostream>
#include<vector>
using namespace std;


// // O(2^n) Time   |   O(n) Space
// int nth_fibo(int num){
//       if(num == 1)
//             return 0;
//       if(num == 2)
//             return 1;
//
//       else{
//              int fib = nth_fibo(num-1) + nth_fibo(num-2) ;
//              return fib;
//       }
// }

// O(n) Time | O(1) Space
int nth_fibo(int num){
      vector<int> v{0, 1};
      int count=3;
      while(count<= num){
            int fib = v[0] + v[1];
            v[0] = v[1];
            v[1] = fib;
            count++;
      }
      return num >1 ? v[1] : v[0];
}

int main(){
      int n;
      cin>>n;
      cout<<nth_fibo(n);
}
