// The Permutation Coefficient represented by P(n, k) is used to represent the number of ways to obtain an ordered subset having k elements
// from a set of n elements.
// P(10, 2) = 90
// P(10, 3) = 720
//@dheeraj
#include<bits/stdc++.h>
using namespace std;

int getPermutaionCoeff(int n, int k){
      int fibo[n+1];
      fibo[0]=1;                                                                    // Taking the first vakue of array as 1 i.e, fatorial of 0 is 1
      for (int i=1; i<=n; i++){
            fibo[i] = i*fibo[i-1];
      }
      return fibo[n]/ fibo[n-k];                                                    //return the value of P(n, k) using the formula method
}


// Driver function
int main(){
      int n, k;
      cout<<"Enter the value of n and k: ";
      cin>>n>>k;                                                                          // Taking the value of n and k
      cout<<"Permutation Coefficient of n and k is: "<<getPermutaionCoeff(n, k);
}
