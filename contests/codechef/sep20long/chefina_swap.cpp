#include<bits/stdc++.h>
using namespace std;

int main() {
      int t;
      cin >> t;
      while(t--) {
            long long n;
            cin >> n;
            long long sum = (n)*(n+1)/2;
            if(sum%2!=0) {
                  cout << 0<<endl;
                  continue;}

            long double temp = sqrtl(1ul+4*(sum));
            temp = temp-1.0;
            temp = temp/2.0;
            long long pos = temp;
            long long partial_sum = pos*(pos+1)/2;

            if(sum/2 == partial_sum) {
                  long long result = (pos*(pos-1ul))/2l+((n-pos)*(n-pos-1ul))/2l+(n-pos);
                  cout <<result<<endl;
            }else  cout <<n-pos<<endl;
      }
}
