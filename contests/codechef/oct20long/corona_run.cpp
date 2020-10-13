#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;
      while(t--){
            int n, k, x, y,i=1, flag=0;
            cin>>n>>k>>x>>y;
            int temp = n;
            // if (n<1) cout<<"NO"<<endl;
            if(n<1 || (x> n-1) || (y>n-1)) cout<<"NO"<<endl;

            else{
                  // cout<<temp;;
                  while(temp--){
                        // cout<<"dh";

                        if((x + k*i)%n == y){
                              cout<<"YES"<<endl;
                              flag = 1;
                              break;
                        }
                        // cout<<'\t'<<i;
                        i++;

                  }
                  if(flag==0) cout<<"NO"<<endl;
            }
      }
}
