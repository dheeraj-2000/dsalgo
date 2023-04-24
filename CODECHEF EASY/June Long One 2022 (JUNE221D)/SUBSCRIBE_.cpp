#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
	    int n, x;
	    cin>>n>>x;
	    int temp = n/6;
	    if(n > temp*6)
	        temp += 1;
	    cout<<temp*x<<endl;
	}
	
	return 0;
}
