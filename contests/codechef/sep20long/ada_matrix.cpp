#include<bits/stdc++.h>
using namespace std;


int misplaced(int arr[][]){

}


int correctplaced(int arr[][]){

}

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
            // for (int i=1; i<n; i++){
            //             cout<< arr[0][i]<< '\t';
            //       // cout<<endl;
            // }

            int correct_placed = 0, mis_placed = 0;

            for(i=n-1; i>0; i++){
                  // if(arr[0][i] == 2 || arr[0][i] == 3 || arr[0][i] == 4 )
                  if(arr[0][i] == i+1)
                        correct_placed = correct_placed + 1;
                  else
                        mis_placed = mis_placed +1;
            }




            if(correct_placed < mis_placed)
                  cout<<correct_placed+1<<endl;
            else
                  cout<<mis_placed<<endl;
            t=t-1;
      }
}
