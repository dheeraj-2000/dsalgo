#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;
      while (t--) {
            long long int n, x, p, k, opern=0;
            cin>>n>>x>>p>>k;
            long int arr[n];

            for(long long int i=0; i<n; i++){
                  cin>>arr[i];
            }

            sort(arr, arr+n);

            if(arr[p-1] == x){
                  cout<<"0"<<endl;
                  continue;
            }

            if (k<=p && arr[p-1]<=x){
                opern=0;
                  for(long long int i=p-1; i<n; i++){
                        if(arr[i]<x)
                              opern++;
                  }
                  cout<<opern<<endl;
                  continue;
            }

            if (k>=p && arr[p-1]>=x){
                opern=0;
                  for(long long int i=p-1; i>=0; i--){
                        if(arr[i]>x)
                              opern++;
                  }
                  cout<<opern<<endl;
                  continue;
            }


            else
                  cout<<"-1"<<endl;
      }
}
