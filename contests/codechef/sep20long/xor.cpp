#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int subMain() {
 long long n, answer = 0;
 cin >> n;
 vector<long long>xorsum;
 long long x;
 for(long long i=1;i<=20;i++) {
  cout << 1 << " " << (1ul<<i) << endl;
  cout.flush();
  cin >> x;
  xorsum.push_back(x);
 }
 reverse(xorsum.begin(), xorsum.end());
 long long sum = xorsum[0]-n*(1ul<<20);
 for(long long i=1;i<xorsum.size();i++) {
  if(xorsum[i] >= sum) {
   xorsum[i] = ((n-(xorsum[i]-sum)/(1ul<<(xorsum.size()-i)))/2);
  }
  else
   xorsum[i] = (n+(sum-xorsum[i])/(1ul<<(xorsum.size()-i)))/2;
 }
 for(int i=1;i<xorsum.size();i++)
  if(xorsum[i]%2 != 0)
   answer+=1ul<<(xorsum.size()-i);
 if(sum%2!=0)
  answer++;
 cout << 2 << " " << answer << endl;
 cout.flush();
 int result;
 cin >> result;
 return result;
}

int main() {
 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 int t = 1;
 cin >> t;
 while(t--) {
  if(!subMain())
   break;
  cout << endl;
  cout.flush();
 }
 return 0;
}
