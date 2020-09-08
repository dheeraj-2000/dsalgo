#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long findPos(long long sum) {
 long double ans = sqrtl(1ul+4*(sum));
 ans = ans-1.0;
 ans = ans/2.0;
 long long finalAns = ans;
 return finalAns;
}

void subMain() {
 long long n;
 cin >> n;        
 long long sum = (n)*(n+1)/2;
 if(sum%2!=0) {
  cout << 0;
  return;
 }
 long long x = findPos(sum);
 long long subsum = x*(x+1)/2;
 if(sum/2 == subsum) {
  long long result = (x*(x-1ul))/2l+((n-x)*(n-x-1ul))/2l+(n-x);
  cout << result;
 }
 else
  cout << n-x;
}

int main() {
 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 int t = 1;
 cin >> t;
 while(t--) {
  subMain();
  cout << "\n";
 }
 return 0;
}
