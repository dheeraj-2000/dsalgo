// Fibonacci numbers are the numbers in the following integer sequence. 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..
// Key: Sum of 'n' Fibonacci sequence will be [](n+2)th term -1]
// @dheeraj

#include<iostream>
using namespace std;

int getSumofn_fibonaacci(int n){
      // int n1=0, n2=1;
      long long int fibo[n+4];
      long int i;
      fibo[0]=0;                 // Declraing 0th term and 1th term to be 1.
      fibo[1]=1;
      for (i=2; i<=n+1; i++){
            fibo[i] = fibo[i-1] + fibo[i-2];                //Adding previous two terms and storing it
      }
      return (fibo[n+1]-1);                                 //returning (n+2)th term -1
}

// Driver Code
int main() {
      /* code */
      long int n;
      cout<<"Enter the Seuence Number: ";
      cin>>n;
      cout<<n<<"th Fibonacci number is: "<<getSumofn_fibonaacci(n);
      return 0;
}
