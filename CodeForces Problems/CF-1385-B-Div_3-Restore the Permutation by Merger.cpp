// Problem Link: https://codeforces.com/contest/1385/problem/B

#include<iostream>
#include<math.h>

using namespace std;
int main()
    {
        long long int t;
        scanf("%lld", &t);
        
        while(t--)
        {
            long long int n , i;
            scanf("%lld", &n);
            long long int arr[2*n];
            
            for(i = 0 ; i < 2*n ; ++i)
            {
              scanf("%lld ", &arr[i]);
            }
          
            long long int table[n*2] = {0};
         
            for(i = 0 ; i < 2*n ; ++i)
            {
          	  //Checking if the value at an index of element number is 0
              if(table[arr[i]] == 0)
              {
              	
              	//incrementing the value to make it non zero
               table[arr[i]]++;         
               printf("%lld ", arr[i]);
               
              }
              
           }
         
            printf("\n");
    }
        return 0;
    }
