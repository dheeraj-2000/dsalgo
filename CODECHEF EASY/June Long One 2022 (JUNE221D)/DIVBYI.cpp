#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
	    int n;
	    cin>>n;
	    int *ans = new int[n];
	    int temp = n;
	    for(int i=n-1; i>=0; i-=2)
	        ans[i] = temp--;
	    for(int i=n-2, c=1; i>=0; i-=2, c++)
	        ans[i] = c;
	    for(int i=0; i<n; i++)
	        cout<<ans[i]<<" ";
	    cout<<endl;
	}
	
	return 0;
}
