/*
link: https://www.codechef.com/SNCK1B21/problems/LARGESTLADDU
*/


#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int t;
	cin>>t;
	
	int n;
	while(t--)
	{
	    cin>>n;
	    int size = 1 << n;
	    
	    vector<int> a(size);
	    for(int i=0; i<size; i++)
	    {
	        cin>>a[i];
	    }
	    
	    int max = *max_element(a.begin(), a.end());
	    int min = *min_element(a.begin(), a.end());
	    
	    if(max - min <= 1)
	        cout<<"YES\n";
	    else
	        cout<<"NO\n";
	}
	return 0;
}

