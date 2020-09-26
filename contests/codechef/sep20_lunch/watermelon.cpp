#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;
      while(t--){
            long int n, sum=0;
            cin>>n;
            long int arr[n];
            // vector<int> v;
            for(int i=0; i<n; i++){
                  long int input;
                  cin>>arr[i];
                //   v.push_back(input);
            }

            // for(auto i: v){
            //       sum = sum+ i;
            // }

            for(int i=0; i<n; i++){
                  sum = sum+ arr[i];
            }


            if (sum < 0)
                  cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;

      }
}
