#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
	    int a, b;
	    cin>>a>>b;
	    int temp = (b-a)%3;
	    if(temp==2)
	        cout<<"NO\n";
	    else
	        cout<<"YES\n";
	}
	
	return 0;
}
