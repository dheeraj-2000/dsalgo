#include<bits/stdc++.h>
using namespace std;
int main(){                                                      // main function
      int t;
      cin>>t;
      while (t--) {
            int n, i, j, count =0;
            cin>>n;
            int arr[64][64];
            for (i=0; i<n; i++){                                  //input
                  for (j=0; j<n; j++)
                        cin>> arr[i][j];
            }
            for(i=n-1; i>0; i--){
                  int temp = i+1;
                  if(temp != arr[0][i]){
                        count = count +1;
                        for (int x = 0; x < 1; x++) {                     //Transpose the matrix (only 1st row with first column)
                              for (int y = x+1; y < i; y++)
                                    swap(arr[x][y], arr[y][x]);
                              }
                  }
            }
            cout<<count<<endl;
}
