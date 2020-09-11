#include<bits/stdc++.h>
using namespace std;


// int misplaced(int arr[][]){
//
// }
//
//
// int correctplaced(int arr[][]){
//
// }

int main(){
      int t;
      cin>>t;
      while (t--) {
            /* code */
            int n, i, j, count =0;
            cin>>n;
            int arr[n][n];
            for (i=0; i<n; i++){
                  for (j=0; j<n; j++)
                        cin>> arr[i][j];
            }

            for(i=n-1; i>0; i--){
                  int temp = i+1;
                  if(temp != arr[0][i]){
                        count = count +1;
                        for (int x = 0; x < i; x++) {
                              for (int y = x+1; y < i; y++) {
                                    swap(arr[x][y], arr[y][x]);
                              }}

                  }

            }

            cout<<count<<endl;
            // for (int i=1; i<n; i++){
            //             cout<< arr[0][i]<< '\t';
            //       // cout<<endl;
            // }

            // int correct_placed = 0, mis_placed = 0;
            //
            // for(i=n-1; i>0; i++){
            //       // if(arr[0][i] == 2 || arr[0][i] == 3 || arr[0][i] == 4 )
            //       if(arr[0][i] == i+1)
            //             correct_placed = correct_placed + 1;
            //       else
            //             mis_placed = mis_placed +1;
            // }
            //
            //
            //
            //
            // if(correct_placed < mis_placed)
            //       cout<<correct_placed+1<<endl;
            // else
            //       cout<<mis_placed<<endl;
            // t=t-1;
      }
}

//
// t=int(input())
// while(t>0):
//     t-=1
//     xx=int(input())
//     count=0;blist=[]
//     for i in range(xx):
//         blist.append([int(x) for x in input().split()])
//     for d in range(xx-1,0,-1):
//         done=blist[d][d-1]+1
//         if done!=blist[d][d]:
//             count+=1
//             don=d+1
//             for i in range(don):
//                 for j in range(i,don):
//                     trav=blist[i][j]
//                     blist[i][j]=blist[j][i]
//                     blist[j][i]=trav
//     print(count)
