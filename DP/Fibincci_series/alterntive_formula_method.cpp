// Fibonacci numbers are the numbers in the following integer sequence. 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..
// Time Complexity: O(1) , Space Complexity : O(1)
// @dheeraj

#include<bits/stdc++.h>
using namespace std;

int getnth_fibonaacci(int n) {
  double phi = (1 + sqrt(5)) / 2;
  return round(pow(phi, n) / sqrt(5));
}

// Driver Code
int main() {
      /* code */
      long int n;
      cout<<"Enter the nth term: ";
      cin>>n;
      cout<<n<<"th Fibonacci number is: "<<getnth_fibonaacci(n);
      return 0;
}
