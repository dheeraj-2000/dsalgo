#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
	    int a, b, n, count=0;
	    cin>>a>>b;
	    n = abs(a-b);
	    for(int i=1; i<=sqrt(n); i++) {
	        if(n%i == 0) {
	            if(n/i == i) 
	                count++;
	            else
	                count += 2;
	        }
	    }
	    cout<<count<<endl;
	}
	
	return 0;
}
