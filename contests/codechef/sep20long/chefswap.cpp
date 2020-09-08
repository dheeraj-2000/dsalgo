#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;
      while(t--){
            int n;
            cin>>n;
            long long sum = n*(n+1)/2;
            if(sum%2!=0) {
                  cout << 0<<endl;
                  continue;
            }

            long double ans = sqrtl(1ul+4*(sum));
            ans = ans-1;
            ans = ans/2;
            long long pos = ans;
            // cout<<pos;

            long long partial_sum = pos*(pos+1)/2;

            if(partial_sum == sum/2){
                  long long nice_swap = pos*(pos-1)/2 + (n-pos)*(n-pos-1)/2 + (n-pos);
                  cout<<nice_swap<<endl;
            }
            else
                  cout<<n-pos<<endl;
      }
}
