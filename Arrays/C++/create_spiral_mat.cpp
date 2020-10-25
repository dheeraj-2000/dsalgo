#include<bits/stdc++.h>
#include<vector>
using namespace std;

int solve(int A) {
      int arr[A][A];
      for(int i=0; i<A; i++){
            for(int j=0; j<A; j++){
                  arr[i][j]= (i)*(A)+(j+1);
            }
      }


      int top=0, down = A-1, left=0, right=A-1, dir = 0;

      while(top >= down && left>= right){
            if(dir ==0){
                  for (int i=left; i<=right; i++)
                        cin>>arr[top][i];
                  top++;
                  dir++;
            }

            if(dir ==1){
                  for (int i=top; i<=down; i++)
                        cin>>arr[i][right];
                  right--;
                  dir++;
            }

            if(dir ==2){
                  for (int i=right; i>=left; i--)
                        cin>>arr[down][i];
                  down--;
                  dir++;
            }
            if(dir ==3){
                  for (int i=down; i>=top; i--)
                        cin>>arr[i][left];
                  left++;
                  dir++;
            }
            dir = dir%4;

      }

}

int main(){
      int n, m, input;
      cin>>n;
      cin>>m;
      vector< vector <int>> v(n, vector<int> (m));
      for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                  cin>>input;
                  v[i].push_back(input);
            }
      }
      solve(v, n, m);
      // for(int i=0; i<v.size(); i++)
      //       cout<<v[i];
}
