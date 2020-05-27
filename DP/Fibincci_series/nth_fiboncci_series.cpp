// Fibonacci numbers are the numbers in the following integer sequence. 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..
// Time Complexity: O(n) , Space Complexity : O(n) 
// @dheeraj

#include<iostream>
using namespace std;

int getnth_fibonaacci(int n){
      // int n1=0, n2=1;
      int fibo[n+2];
      int i;
      fibo[0]=0;                 // Declraing 0th term and 1th term to be 1.
      fibo[1]=1;
      for (i=2; i<=n; i++){
            fibo[i] = fibo[i-1] + fibo[i-2];                //Adding previous two terms and storing it
      }
      return fibo[n];
}

// Driver Code
int main() {
      /* code */
      int n;
      cout<<"Enter the nth term: ";
      cin>>n;
      cout<<n<<"th Fibonacci number is: "<<getnth_fibonaacci(n);
      return 0;
}
