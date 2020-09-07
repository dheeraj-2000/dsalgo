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
            for (int i=1; i<n; i++){
                        cout<< arr[0][i]<< '\t';
                  // cout<<endl;
            }

            // int correct_placed = 0, mis_placed = 0;
            //
            // for(i=; i<n; i++){
            //       if(arr[1][i] == 2 || arr[1][i] == 3 || arr[1][i] == 4 )
            //             correct_placed = correct_placed +1;
            //       else
            //             mis_placed = mis_placed +1;
            // }
            t=t-1;
      }
}
