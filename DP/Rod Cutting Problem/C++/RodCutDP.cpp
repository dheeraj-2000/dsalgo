// Authored by Gourab Chakraborty, IIIT Dharwad 19BCS118

#include <bits/stdc++.h> 

using namespace std;

int max(int a, int b) { return (a > b)? a : b;} 
  
int cutRod(int price[], int n) 
{ 
   int val[n+1]; 
   val[0] = 0; 
   int i, j; 
  
   // Build the table val[] in bottom up manner and return the last entry 
   // from the table 
   for (i = 1; i<=n; i++) 
   { 
       int max_val = INT_MIN; 
       for (j = 0; j < i; j++) 
         max_val = max(max_val, price[j] + val[i-j-1]); 
       val[i] = max_val; 
   } 
  
   return val[n]; 
} 
  
int main() 
{ 
    int arr[100];
    int n;
    cout<<"Enter Array size:"<<endl;
    cin>>n;
    for(long long int i=0; i<n; i++)
       cin>>arr[i];
    int size = n; 
    printf("Maximum Obtainable Value is %d \n", cutRod(arr, size)); 
    getchar(); 
    return 0; 
} 