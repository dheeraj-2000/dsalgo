#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
	    int x,y;
	    cin>>x>>y;
	    
	    if(y <= (x*1.07))
	        cout<<"YES"<<endl;
	    else
	        cout<<"NO"<<endl;
	}
	
	return 0;
}
