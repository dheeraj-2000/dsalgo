// Catalan numbers form a sequence of natural numbers that occur in various counting problems
// examples are : 1 1 2 5 14 42 132 429 1430 4862
// complexity using DP is O(n^2)
// @dheeraj

#include<bits/stdc++.h>
using namespace std;

unsigned long int get_nth_catalan_number(unsigned int n){
      unsigned long int cat[n+1];
      cat[0]=1;
      cat[1]=1;
      for (int i=2; i<n; i++){
            cat[i]=0;
            for (int j=0; j<i; j++){
                  cat[i]+= cat[j]*cat[i-j-1];
            }
      }
      return cat[n];
}


// Driver function
int main (){
      int n;
      cout<<"Enter the nth number: ";
      cin>>n;
      cout<<n<<"th Catalan number will be: "<<get_nth_catalan_number(n);

}
