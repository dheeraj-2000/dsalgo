#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
	    int n, a, b, c, d;
	    cin>>n;
	    cin>>a>>b>>c>>d;
	    
	    if(a>=b && a>=c && a>=d && a<=n)
	        cout<<a<<endl;
	    else if(b>=a && b>=c && b>=d && b<=n)
	        cout<<b<<endl;
	    else if(c>=a && c>=b && c>=d && c<=n)
	        cout<<c<<endl;
	    else
	        cout<<d<<endl;
	}
	
	return 0;
}
