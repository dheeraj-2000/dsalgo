#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
	    int n;
	    cin>>n;
	    
	    // Since after spending 20%, 20% and 30%, the remaining profit is 30% -> 15 coins per sale
	    cout<<n*15<<endl;
	}
	
	return 0;
}
