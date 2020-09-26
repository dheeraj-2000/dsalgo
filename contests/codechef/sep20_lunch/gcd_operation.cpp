#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;
      while(t--){
            long int n, temp=1;
            cin>>n;
            long int dh[n];

            for(int i=0; i<n; i++){
                  cin>>dh[i];
            }

            for(int i=0; i<n; i++){
                  if((i+1) % dh[i] == 0){
                        continue;
                  }
                  else{
                        temp=0;
                        break;
                  }
            }

            if(temp==1)
                  cout<<"YES"<<endl;
            else
                  cout<<"NO"<<endl;
      }
}
