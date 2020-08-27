#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
      int arr[3] = {3,2,4};
      int t = 6;
      int temp, i, j;

      for (i=0; i<6; i++){
            temp = arr[i];
            int val = t-temp;
            for(j=i+1; j<6; j++){
                  if(arr[j]==val)
                        cout << i<<'\t' << j;
            }



      }
}
