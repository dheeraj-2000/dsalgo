#include<bits/stdc++.h>
using namespace std;


//Time Complexity O(n)
int MaxSum_subarray_length(int arr[], int n, int maxsum){
      int maxlen =0, count=0, sum=0;

      for(int i=0; i<n; i++){
            if(sum + arr[i]<=maxsum){
                  sum+= arr[i];
                  count++;
            }
            else{
                  sum = sum -arr[i-count]+arr[i];
            }

            maxlen = max(count, maxlen);
      }
      return maxlen;
}

// Driver code
int main(){
      int n, maxsum;
      cin>>n;
      int arr[n];
      for (int i=0; i<n; i++){
            cin>>arr[i];
      }
      cout << "enter the sum of elements of the subarray: ";
      cin>> maxsum;
      MaxSum_subarray_length(arr, n, maxsum);
      cout<<"The lenth of longest sumarray whose elements sum is "<<maxsum<< ": "<< MaxSum_subarray_length(arr, n, maxsum);
}
