#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
	    int n, a[1000];
	    cin>>n;
	    
	    for(int i=0; i<n; i++)
	        cin>>a[i];
	    
	    int temp = n-1;
	    
	    while(a[temp] == 0)
	        temp--;
	    
	    cout<<temp<<endl;
	}
	
	return 0;
}
