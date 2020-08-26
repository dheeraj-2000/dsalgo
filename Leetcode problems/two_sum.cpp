#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
      int arr[6] = {2, 5, 6, 1, 9, 3};
      int t = 10;
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
