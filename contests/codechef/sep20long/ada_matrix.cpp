#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;
      while (t !=0) {
            /* code */
            int n, i, j;
            cin>>n;
            int arr[n][n];
            for (i=0; i<n; i++){
                  for (j=0; j<n; j++)
                        cin>> arr[i][j];
            }
            for (int i=0; i<n; i++){
                  for (int j=0; j<n; j++)
                        cout<< arr[i][j];
                  // cout<<endl;
            }

            t=t-1;
      }
}
