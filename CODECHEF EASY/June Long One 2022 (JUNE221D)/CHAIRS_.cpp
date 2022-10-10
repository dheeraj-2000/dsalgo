#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
	    int x, y;
	    cin>>x>>y;
	    if(x>y)
	        cout<<x-y<<endl;
	    else
	        cout<<0<<endl;
	}
	
	return 0;
}
