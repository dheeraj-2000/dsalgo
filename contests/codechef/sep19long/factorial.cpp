#include <map>
#include <iostream>
#include<cmath>
using namespace std;

#define long long long
const long M = 1000000007; // modulo
map<long, long> F;

long f(long n) {
	if (F.count(n)) return F[n];
	long k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
	} else { // n=2*k+1
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
	}
}

main(){
  int t;
  cin>>t;
  while(t--){
	long n,ans;
  cin>>n;
  ans= (long)(log(n)/log(2));
  //cout<<ans<<endl;
  ans = pow(2,ans);
   //cout<<ans<<endl;

	F[0]=F[1]=1;
 ans= ans-1;
 //cout<<ans<<endl;
	cout << (ans ==0 ? 0 : f(ans-1))%10 << endl;
}
}
