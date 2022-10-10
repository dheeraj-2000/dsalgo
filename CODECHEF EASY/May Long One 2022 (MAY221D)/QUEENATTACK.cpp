#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
	    int n, x, y, count=0;
	    cin>>n>>x>>y;
	    
	    // Adding under-attack horizontal and vertical elements
	    count = 2*(n-1);
	    
	    // Adding under-attack north-east elements
	    if(x-1>0 && n-y>0)
	        count += min(x-1, n-y);
	    
	    // Adding under-attack south-east elements
	    if(n-x>0 && n-y>0)
	        count += min(n-x, n-y);
	    
	    // Adding under-attack south-west elements
	    if(n-x>0 && y-1>0)
	        count += min(n-x, y-1);
	        
	    // Adding under-attack north-west elements
	    if(x-1>0 && y-1>0)
	        count += min(x-1, y-1);
	        
	    cout<<count<<endl;
	}
	
	return 0;
}
